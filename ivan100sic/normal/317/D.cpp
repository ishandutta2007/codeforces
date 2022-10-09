// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void mex_add(uint32_t& x, int i) {
    x |= 1u << i;
}

int mex_get(uint32_t x) {
    return __builtin_ctz(~x);
}

int compute_nimber(int n) {
    vector<uint8_t> a(1 << n);
    vector<uint32_t> masks(n+1);
    for (int i=1; i<=n; i++) {
        uint32_t& m = masks[i];
        for (int j=i; j<=n; j+=i) {
            m |= 1u << (j - 1);
        }
    }

    for (int mask=0; mask<(1<<n); mask++) {
        uint32_t mexer = 0;
        for (int j=1; j<=n; j++) {
            if (mask & (1 << (j - 1))) {
                mex_add(mexer, a[mask & ~masks[j]]);
            }
        }
        a[mask] = mex_get(mexer);
    }

    return a.back();
}

void compute_dump_all_nimbers() {
    for (int x=1; x<=30; x++) {
        cerr << x << ' ' << compute_nimber(x) << '\n';
    }
}

// output of above
int nimbers[] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, z = 1;
    cin >> n;
    vector<int> mark(40000);
    int b1 = n - 1;
    for (int x=2; x*x<=n; x++) {
        if (!mark[x]) {
            int e = 0;
            for (ll y=x; y<=n; y*=x) {
                if (y*y<=n) {
                    mark[y] = 1;
                }
                e++;
            }
            b1 -= e;
            z ^= nimbers[e];
        }
    }
    z ^= (b1 & 1);
    cout << (z ? "Vasya\n" : "Petya\n");
}