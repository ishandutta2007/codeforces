//-Wl,--stack=128000000 -std=c++11 -static-libgcc
#pragma GCC optimize(2)
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int P = 1e9+7;
const int N = 100050;
template <typename T>
void read(T &x) {
    x = 0; char c = getchar();
    while (!isdigit(c)) c=getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
}
int ch[N<<4][2], siz[N<<4];
ll a[N], tot, cnt = 1, n;
inline void ins(int x) {
    int p = 1; siz[1]++;
    for (int i = 30;i >= 0; i--) { 
        int di = (x >> i) & 1;
        if (!ch[p][di]) ch[p][di] = ++cnt;
        p = ch[p][di]; siz[p]++;
    }
}

ll K, k, lim, ans;
int bit[N][33], p[N];

int main() {
    read(n), read(K);
    for (int i = 1;i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n;i >= 1; i--) {
        ins(a[i]), p[i] = 1;
        for (int j = 0;j <= 30; j++)
            bit[i][j] = bit[i+1][j] + ((a[i] >> j) & 1);
    }

    k = K;
    for (int i = 30;i >= 0; i--) {
        ll sum = 0;
        for (int j = 1;j <= n; j++) 
            sum += siz[ch[p[j]][!((a[j] >> i) & 1)]];
        sum >>= 1;
        for (int j = 1;j <= n; j++) {
            int di = (a[j] >> i) & 1;
            if (sum < k) p[j] = ch[p[j]][di];
            else p[j] = ch[p[j]][!di];
        }
        if (sum < k) k -= sum;
		else lim |= 1 << i;
    }
    
    for (int i = 30;i >= 0; i--) {
        if ((lim >> i) & 1) continue;
        int t = (lim >> i | 1) << i;
        for (int j = 1;j <= n; j++) {
            int l = ((a[j] ^ t) >> i) << i, r = l | ((1 << i) - 1);
            l = lower_bound(a + 1, a + n + 1, l) - a;
            r = upper_bound(a + 1, a + n + 1, r) - a;
            if (l == r) continue;
            ans += (ll)t * (r - l);
            tot += r - l - (l <= j && j < r);
            for (int k = i - 1;k >= 0; k--) {
                int res = bit[l][k] - bit[r][k];
                if ((a[j] >> k) & 1) res = r - l - res;
                ans += (ll)(1 << k) * res;
            }
        }
    }
    ans >>= 1, tot >>= 1;
    cout << (ans + (K - tot) * lim) % P << endl;
    return 0;
}