#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
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
const int N=1e5+10;

int m,n;
ii a[N];
void solve(){
    int ans=a[1].Y;
    REP(i,1,n){
        int dis=abs(a[i+1].X-a[i].X),change=abs(a[i+1].Y-a[i].Y);
        if (change>dis){
            printf("IMPOSSIBLE");
            return;
        }
        dis-=change;
        ans=max(ans,max(a[i+1].Y,a[i].Y)+dis/2);
    }
    cout<<ans;
}
int main(){
    scanf("%d%d",&m,&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    int tmp=n;
    if (a[1].X!=1) a[++n]=ii(1,a[1].Y+a[1].X-1);
    if (a[tmp].X!=m) a[++n]=ii(m,a[tmp].Y+m-a[tmp].X);
    sort(a+1,a+n+1);
    solve();
}