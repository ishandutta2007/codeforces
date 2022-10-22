#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5, mod = 1e9 + 9;

int n, q, s, fib[MAXN], pref[MAXN];
int l[1010], r[1010]; // query
int lz[MAXN], a[MAXN], sum[MAXN];

inline int add(int a, int b) {
    a += b; return a < mod ? a : a - mod;
}

inline int sub(int a, int b) {
    return add(a, mod - b);
}

int main() {
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    
    fib[1] = pref[1] = 1;
    for (int i = 2; i < MAXN; ++i){
        fib[i] = add(fib[i - 1], fib[i - 2]);
        pref[i] = add(fib[i], pref[i - 1]);
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = add(a[i], sum[i - 1]);
    }
    for (int i = 1, tp; i <= q; i++){
        cin >> tp >> l[s] >> r[s];
        if (tp == 1) {
            lz[l[s]] = add(lz[l[s]], 1);
            lz[r[s] + 1] = sub(lz[r[s] + 1], fib[r[s] - l[s] + 2]);
            lz[r[s] + 2] = sub(lz[r[s] + 2], fib[r[s] - l[s] + 1]);   
            if (++s >= 700){
                sum[1] = a[1] = add(a[1], lz[1]);
                for (int i = 2; i <= n; i++){
                    lz[i] = add(add(lz[i], lz[i - 1]), lz[i - 2]);
                    a[i] = add(a[i], lz[i]);
                    sum[i] = add(sum[i - 1], a[i]);
                }
                for (int i = 1; i <= n; i++)
                    lz[i] = 0;
                s = 0;
            }
        }else{
            int ans = sub(sum[r[s]], sum[l[s] - 1]);
            for (int i = 0, tl, tr; i < s; i++){
                tl = max(l[i], l[s]), tr = min(r[i], r[s]);
                if (tl <= tr)
                    ans = add(ans, sub(pref[tr - l[i] + 1], pref[tl - l[i]]));
            }
            cout << ans << "\n";
        }
    }
}