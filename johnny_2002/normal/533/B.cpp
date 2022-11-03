#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e16;
const int MOD=1e9+7;
const int N=2e5+10;

template <class T>
void maximize(T &x,T y){
    if (x<y) x=y;
}
ll f[N][2][2],tmp[2][2];
int w[N],n;
vector <int> a[N];
void DFS(int x){
    f[x][0][0]=f[x][1][0]=0;
    f[x][0][1]=f[x][1][1]=-inf;
    for(auto y:a[x]){
        DFS(y);
        FOR(i,0,1)
            FOR(j,0,1) tmp[i][j]=f[x][i][j];
        maximize(f[x][1][1],tmp[1][0]+max(f[y][1][1],f[y][0][1]));
        maximize(f[x][1][1],tmp[1][1]+f[y][0][0]);
        maximize(f[x][1][0],tmp[1][1]+max(f[y][1][1],f[y][0][1]));
        maximize(f[x][1][0],tmp[1][0]+f[y][0][0]);
        maximize(f[x][0][0],max(tmp[0][0]+f[y][0][0],tmp[0][1]+max(f[y][0][1],f[y][1][1])));
        maximize(f[x][0][1],max(tmp[0][0]+max(f[y][1][1],f[y][0][1]),tmp[0][1]+f[y][0][0]));
    }
    f[x][1][1]=f[x][1][0]+w[x];
    f[x][1][0]=-inf;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x;
        scanf("%d%d",&x,w+i);
        if (x!=-1) a[x].push_back(i);
    }
    DFS(1);
    ll ans=0;
    //FOR(i,1,n) printf("%lld %lld %lld\n",f[i][1][1],f[i][0][1],f[i][0][0]);
    FOR(i,0,1)
        FOR(j,0,1) ans=max(ans,f[1][i][j]);
    cout<<ans;
}