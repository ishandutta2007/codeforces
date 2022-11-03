#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e2+10;

int n,a[N],f[N][N][2],g[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    FOR(i,1,n)
        FOR(j,i,n) f[i][j][0]=f[i][j][1]=inf;
    FOR(i,1,n) f[i][i][0]=f[i][i][1]=1;
    REP(i,1,n) f[i][i+1][0]=f[i][i+1][1]=1+(a[i]!=a[i+1]);
    FORD(L,n,1)
        FOR(R,L+2,n){
            REP(mid,L,R) {
                f[L][R][0]=min(f[L][R][0],f[L][mid][0]+f[mid+1][R][0]);
                f[L][R][1]=min(f[L][R][1],min(min(f[L][mid][1]+f[mid+1][R][0],f[L][mid][0]+f[mid+1][R][1]),f[L][mid][1]+f[mid+1][R][1]));
            }
            if (a[L]==a[R]) f[L][R][1]=min(f[L][R][1],min(f[L+1][R-1][1],f[L+1][R-1][0]+1));
            f[L][R][0]=min(f[L][R][0],f[L][R][1]);
//            cout<<L<<" "<<R<<" "<<f[L][R][0]<<" "<<f[L][R][1]<<'\n';
        }
//    FOR(i,1,n)
//        FOR(j,i,n) cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<'\n';
    cout<<f[1][n][0];
}
int main(){
    prepare();
    solve();
}