// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T, int N, int B> 
struct asym_ra {
    T a[N+1];
    T b[N/B+2];

    T get(int r) {
        if (r <= 0) return T();
        if (r > N) r = N;

        return a[r] + b[r / B];
    }

    T operator() (int l, int r) {
        return get(r) - get(l);
    }

    void add(int p, const T& v) {
        for (int i=p+1; i%B && i<=N; i++) a[i] += v;
        for (int i=p/B+1; i<N/B+2; i++) b[i] += v;
    }
};

int n;
int a[200005];
const int H = 300000;
asym_ra<ll, H+5, 512> cnt;
asym_ra<ll, H+5, 512> sum;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    ll sol = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        // svi modulo ja
        for (int j=0; j<=H; j+=x) {
            sol += sum(j, j+x) - cnt(j, j+x)*1ll*j;
        }

        // cerr << "izmedju " << sol << '\n';

        // ja modulo svi
        for (int q=1;;) {
            // x / what = q?
            // inclusive:
            int r = x / q;
            int l = x / (q + 1) + 1;
            // cerr << x << ' ' << q << ' ' << l << ' ' << r << '\n';
            // [l, r) kako i dolikuje
            r++;
            // okej
            sol += x*cnt(l, r) - q*sum(l, r);
            // sledeci q
            if (l == 1) break; // gotovo
            q = x/(l-1);
        }

        // svi veci od mene
        sol += x * 1ll * cnt(x+1, H+1);

        cout << sol << ' ';
        cnt.add(x, 1);
        sum.add(x, x);
    }
    cout << '\n';
}