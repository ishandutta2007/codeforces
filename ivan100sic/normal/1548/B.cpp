// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct monotonic_queue {
    struct node { T v, s; };
    vector<node> a, b;
    T e;
    F f;

    monotonic_queue(T e = T(), F f = F()) : e(e), f(f) {}

    void push(vector<node>& a, const T& v) {
        if (a.size())
            a.push_back({v, f(a.back().s, v)});
        else
            a.push_back({v, v});
    }

    void rotate() {
        while (a.size()) {
            push(b, a.back().v);
            a.pop_back();
        }
    }

    monotonic_queue& operator+= (const T& x) {
        push(a, x);
        return *this;
    }

    T operator() () const {
        T x = e;
        if (a.size()) x = f(x, a.back().s);
        if (b.size()) x = f(x, b.back().s);
        return x;
    }

    void pop() {
        if (!b.size())
            rotate();
        b.pop_back();
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n-1);
        for (ll& x : a) cin >> x;
        for (int i=0; i<n-1; i++) {
            b[i] = abs(a[i] - a[i+1]);
        }

        monotonic_queue mq(0ll, [](ll x, ll y) { return gcd(x, y); });

        n--;
        int z = 0;
        for (int l=0, r=0; l<n; l++) {
            r = max(l, r);
            while (r < n && gcd(mq(), b[r]) > 1) {
                mq += b[r++];
            }

            if (l == r) {
                r++;
            } else {
                z = max(z, r-l);
                mq.pop();
            }
        }
        cout << z+1 << '\n';
    }
    
}