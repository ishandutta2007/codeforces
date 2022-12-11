#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 200500;
template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-')f=1;
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    if (f) x=-x;
}

ll n, m, p, h, t, x;
ll d[N], q[N], y[N], sum[N];
ll a[N], f[105][N];
const ll inf = 1e15;
int main() {
    read(n), read(m), read(p);
    for (int i = 2;i <= n; i++) read(d[i]), d[i] += d[i-1];
    for (int i = 1;i <= m; i++) 
        read(x), read(a[i]), a[i] -= d[x];
    sort(a + 1, a + m + 1);
    for (int i = 1;i <= m; i++) sum[i] = sum[i-1] + a[i];
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1;i <= p; i++) {
        h = t = 1; q[1] = 0;
        for (int j = 1;j <= m; j++) y[j] = f[i-1][j] + sum[j];
        for (int j = 1;j <= m; j++) {
            while (h < t && (y[q[h+1]] - y[q[h]]) <= a[j] * (q[h+1] - q[h])) h++;
            f[i][j] = min(f[i-1][j], f[i-1][q[h]] + (j - q[h]) * a[j] - (sum[j] - sum[q[h]]));
            // if (y[j] >= inf) continue;
            while (h < t && (y[q[t]] - y[q[t-1]]) * (j-q[t]) >= (y[j] - y[q[t]]) * (q[t] - q[t-1])) t--;
            q[++t] = j;
        }
    }
    cout << f[p][m] << endl;
}