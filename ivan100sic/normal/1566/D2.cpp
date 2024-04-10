// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct fenwick {
    vector<T> a;
    T e;
    F f;

    fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

    void add(int p, const T& v) {
        for (p++; p <= (int)a.size(); p += p & -p)
            a[p-1] = f(a[p-1], v);
    }

    T operator() (int p) const {
        T v = e;
        for (; p; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n*m);
        map<int, int> xc;
        map<int, vector<int>> seat;
        for (int i=0; i<n*m; i++) {
            cin >> a[i];
            xc[a[i]]++;
        }

        int l = 0;
        for (const auto& [k, v] : xc) {
            int r = l + v;

            for (int row=n-1; row>=0; row--) {
                int xl = max(l, row * m);
                int xr = min(r, (row + 1) * m);

                for (int i=xl; i<xr; i++) {
                    seat[k].push_back(i);
                }
            }

            l = r;
        }

        vector fen(n, fenwick(m, 0));

        int z = 0;

        for (int x : a) {
            int s = seat[x].back();
            seat[x].pop_back();

            int r = s / m, c = s % m;

            z += fen[r](c);
            fen[r].add(c, 1);
        }

        cout << z << '\n';
    }
}