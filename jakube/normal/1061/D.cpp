#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class Modular {
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    int value;
    static const int MOD_value = MOD;
};

using ModInt = Modular<1'000'000'007>;

struct Event
{
    int time;
    int type; // 0 = l, 1 = r
    int start;
    bool operator<(Event const& o) const {
        return make_pair(time, type) < make_pair(o.time, o.type);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x, y;
    cin >> n >> x >> y;
    x -= y;

    vector<pair<int, int>> lr(n);
    for (auto& x : lr)
        cin >> x.first >> x.second;

    vector<Event> events(2*n);
    for (int i = 0; i < n; i++) {
        events[2*i] = {lr[i].first, 0, lr[i].first};
        events[2*i+1] = {lr[i].second, 1, lr[i].first};
    }
    sort(events.begin(), events.end());
    
    ModInt result = 0;
    priority_queue<int> ended;
    for (auto e : events) {
        if (e.type == 0) {
            if (ended.empty() || (e.time - ended.top() - 1) * y > x) {
                result += x;
            } else {
                result += (e.time - ended.top() - 1) * y;
                ended.pop();
            }
        } else {
            result += (e.time - e.start + 1) * y;
            ended.push(e.time);
        }
    }
    cout << result << '\n';
}