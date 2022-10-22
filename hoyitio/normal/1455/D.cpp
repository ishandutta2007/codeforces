#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 505;
int dp[maxn][maxn][maxn];
int a[maxn];
const int inf = 0x3f3f3f3f;
int main()
{
    int T; cin>>T;
    while(T--){
        int n, x;
        scanf("%d%d", &n, &x);
        assert(n <= 500);
        assert(x <= 500 && x >= 0);
        fors(i,1,n+1) {
            scanf("%d", &a[i]);
            assert(a[i] <= 500 && a[i] >= 0);
            fors(j,0,maxn) fors(k,0,maxn) dp[i][j][k] = inf;
        }
        dp[1][a[1]][x] = 0;
        if(x < a[1]) dp[1][x][a[1]] = 1;
        fors(i,1,n){
            fors(j,0,maxn){
                fors(k,0,maxn){
                    if(dp[i][j][k] == inf) continue;
                    //if(dp[i][j][k] != inf) cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" val:"<<dp[i][j][k]<<endl;
                    if(a[i+1] >= j){
                        //cout<<"?"<<endl;
                        dp[i+1][a[i+1]][k] = min(dp[i+1][a[i+1]][k], dp[i][j][k]);
                    }
                    if(k >= j && a[i+1] > k){
                        dp[i+1][k][a[i+1]] = min(dp[i+1][k][a[i+1]], dp[i][j][k] + 1);
                    }
                }
            }
        }
        int ans = inf;
        fors(i,0,maxn){
            fors(j,0,maxn) {
                ans = min(ans, dp[n][i][j]);
            }
        }
        if(ans == inf) printf("-1\n");
        else printf("%d\n", ans);
    }
}
/*
5 2
1 2 3 4 5


*/