#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int vis[105];
int main()
{
    int T; cin>>T;
    while(T--){
        memset(vis, 0, sizeof vis);
        int n, m; scanf("%d%d", &n, &m);
        fors(i,0,n) {
            int x; scanf("%d", &x); vis[x] = 1;
        }
        int ans = 0;
        fors(i,0,m){
            int x; scanf("%d", &x); if(vis[x]) ans++;
        }
        printf("%d\n", ans);
    }
}