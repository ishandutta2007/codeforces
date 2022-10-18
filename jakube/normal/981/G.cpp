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

using ModInt = Modular<998244353>;

struct LinearFunktion
{
    ModInt k = 1, d = 0;
    void compose(LinearFunktion f) {
        k *= f.k;
        d = f.k * d + f.d;
    }
};

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.resize(4 * n);
    }

    ModInt sum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return 0;
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return sum(x, y, id << 1, l, m) + sum(x, y, id << 1 | 1, m, r);
        }
    }

    void apply(int x, int y, LinearFunktion f, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            data[id] = data[id] * f.k + f.d * (r - l);
            todo[id].compose(f);
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            apply(x, y, f, id << 1, l, m);
            apply(x, y, f, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

private:
    void push(int id, int l, int r)
    {
        int m = (l + r) >> 1;

        data[id << 1] *= todo[id].k;
        data[id << 1] += todo[id].d * (m - l);
        todo[id << 1].compose(todo[id]);

        data[id << 1 | 1] *= todo[id].k;
        data[id << 1 | 1] += todo[id].d * (r - m);
        todo[id << 1 | 1].compose(todo[id]);

        todo[id] = {1, 0};
    }

    int n;
    vector<ModInt> data;
    vector<LinearFunktion> todo;
};

struct Interval
{
    int l, r, color;
    bool operator<(const Interval& o) const {
        return l < o.l;
    }
};

class TwoColorPartition
{
public:
    TwoColorPartition(int n) {
        s.insert({0, n-1, 0});
    }

    using It = set<Interval>::iterator;

    void split(int x) {
        // x becomes the left border of interval
        auto it = s.upper_bound({x, 0, 0});
        --it;
        if (it->l < x) {
            auto I = *it;
            s.erase(it);
            s.insert({I.l, x-1, I.color});
            s.insert({x, I.r, I.color});
        }
    }

    pair<It, It> get_iterators(int l, int r) {
        split(l);
        split(r+1);
        return {s.lower_bound({l, 0, 0}), s.upper_bound({r, 0, 0})};
    }

    void color(It lit, It rit, int c) {
        int l = lit->l;
        auto tmp = rit;
        --tmp;
        int r = tmp->r;
        s.erase(lit, rit);
        s.insert({l, r, c});
    }

private:
    set<Interval> s;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    SegmentTreeRecLazy st(n);
    vector<TwoColorPartition> partition(n + 1, n);
    LinearFunktion Increment = {1, 1}, Double = {2, 0};
    for (int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            int x;
            cin >> x;
            auto [lit, rit] = partition[x].get_iterators(l, r);
            for (auto it = lit; it != rit; ++it) {
                st.apply(it->l, it->r+1, it->color == 0 ? Increment : Double);
            }
            partition[x].color(lit, rit, 1);
        } else {
            cout << st.sum(l, r+1) << '\n';
        }
    }
}