#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;
 
int n,m,t,b,cnt,sel[N],mark[N],ok[N];
vector<int> v,g[N];
 
void dfs(int x){
    cnt++;
    mark[x]=1;
    if(!ok[x]){
        f(i,0,g[x].size()) ok[g[x][i]]=1;
        v.pb(x);
    }
    f(i,0,g[x].size())
        if(!mark[g[x][i]])
            dfs(g[x][i]);
}
void Dfs(int x){
    cnt++;
    mark[x]=1;
    f(i,0,g[x].size()){
        if(sel[x] && sel[g[x][i]]) b=1;
        if(!mark[g[x][i]] && (sel[x] || sel[g[x][i]]))
            Dfs(g[x][i]);
    }
    
}
void check(){
    b=0;
    cnt=0;
    f(i,0,v.size()) sel[v[i]]=1;
    Dfs(1);
    if(cnt<n || b){
        while(1){
            cnt++;
        }
    }
    fill(sel,sel+n+1,0);
    fill(mark,mark+n+1,0);
}
void solve(){
    cnt=0;
    v.clear();
    f(i,1,n+1) g[i].clear();
    cin>>n>>m;
    f(i,0,m){
        int u,v;
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    fill(ok,ok+n+1,0);
    fill(mark,mark+n+1,0);
    if(cnt<n) cout<<"NO"<<'\n';
    else{
        check();
        cout<<"YES"<<'\n'<<v.size()<<'\n';
        f(i,0,v.size()) cout<<v[i]<<" ";
        cout<<'\n';
    }
}
 
int main(){
	cin>>t;
	while(t--)
	    solve();
}