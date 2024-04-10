#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int a[maxn], b[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n, m;
        scanf("%d", &n);
        int mx = 0, mx2 = 0;
        fors(i,1,n+1) scanf("%d", &a[i]), a[i] += a[i-1], mx = max(mx, a[i]);
        scanf("%d", &m);
        fors(i,1,m+1) scanf("%d", &b[i]), b[i] += b[i-1], mx2 = max(mx2, b[i]);
        printf("%d\n", mx + mx2);
    }
}