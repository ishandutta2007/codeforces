#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int f[2][N],a[N],n,m,x;
int power(int x,int y){
    int ans=1;
    while (y){
        if (y&1) ans*=x;
        x=x*x;
        y>>=1;
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&x);
    int bar=power(x,m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) f[0][i]=f[0][i-1]|a[i];
    FORD(i,n,1) f[1][i]=f[1][i+1]|a[i];
    ll ans=0;
    FOR(i,1,n) ans=max(ans,(1LL*a[i]*bar)|f[0][i-1]|f[1][i+1]);
    cout<<ans;
}