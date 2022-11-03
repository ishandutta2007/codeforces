#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
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

int n,x,y,lv[N],c[N];
int f[N];
vector <int> a[N];
void DFS1(int par,int x){
    if (a[x].size()==(par>0)){
        f[x]=c[x]=1;
        return;
    }
    if (lv[x]%2==0) f[x]=inf;
    for(auto y:a[x]) if (y!=par){
        lv[y]=lv[x]+1;
        DFS1(x,y);
        c[x]+=c[y];
        if (lv[x]%2) f[x]+=f[y];
        else f[x]=min(f[x],f[y]);
    }
}
void DFS2(int par,int x){
    if (a[x].size()==(par>0)){
        f[x]=1;
        return;
    }
    if (lv[x]%2) f[x]=inf;
    for(auto y:a[x]) if (y!=par){
        DFS2(x,y);
        if (lv[x]%2) f[x]=min(f[x],f[y]);
        else f[x]+=f[y];
    }
}
void solve(){
    DFS1(0,1);
    printf("%d ",c[1]-f[1]+1);
    memset(f,0,sizeof(f));
    DFS2(0,1);
    printf("%d",f[1]);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n-1) {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    solve();
}