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
const int N=1e5+10;

ii ans[N];
int a[N][2],p[N],n,m;
bool comp(int x,int y){
    if (a[x][0]==a[y][0]) return a[x][1]>a[y][1];
    return a[x][0]<a[y][0];
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d",&a[i][0],&a[i][1]);
    FOR(i,1,m) p[i]=i;
    sort(p+1,p+m+1,comp);
}
void solve(){
    int cur=1,c=0,x=0,y=2;
    FOR(i,1,m) if (!a[p[i]][1]){
        c++;
        if (c>1LL*(cur-1)*(cur-2)/2){
            printf("-1");
            return;
        }
        x++;
        if (x==y-1) x=1,y++;
        ans[p[i]]=ii(x,y);
    }else {
        cur++;
        ans[p[i]]=ii(cur-1,cur);
    }
    FOR(i,1,m) printf("%d %d\n",ans[i].X,ans[i].Y);
}
int main(){
    prepare();
    solve();
}