#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=1e5+10;

int n,f[N],p[N];
ii a[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+n+1);
    FOR(i,1,n) p[i]=a[i].X;
}
int solve(){
    int ans=n+1;
    FOR(i,1,n){
        int idx=lower_bound(p+1,p+n+1,a[i].X-a[i].Y)-p;
        f[i]=f[idx-1]+(i-idx);
        ans=min(ans,f[i]+(n-i));
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}