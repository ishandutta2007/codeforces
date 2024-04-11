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

const int N=4e5;

int n,m,c,ans,a[N],mark[N],in[N];
vector<int> V,v[N],g[N],gb[N];

int T(int x,int y){
    return x*m+y;    
}
void Add_edge(int u,int v){
    g[u].pb(v);
    gb[v].pb(u);
}
void dfs1(int u){
    mark[u]=1;
    f(i,0,gb[u].size())
        if(!mark[gb[u][i]])
            dfs1(gb[u][i]);
    V.pb(u);
}
void dfs2(int u){
    mark[u]=c;
    //cout<<u<<" "<<c<<endl;
    f(i,0,g[u].size()){
        if(!mark[g[u][i]])
            dfs2(g[u][i]);
        else if(mark[g[u][i]]!=c)
            in[mark[g[u][i]]]=1;
    }
}
void find_strongly(){
    f(i,0,n)
        f(j,0,v[i].size())
            if(!mark[T(i,v[i][j])])
                dfs1(T(i,v[i][j]));
    fill(mark,mark+N,0);
    f_(i,V.size()-1,0)
        if(!mark[V[i]]){
            c++;
            dfs2(V[i]);
        }
}

int main(){
    fill(a,a+N,N);
    cin>>m>>n;
    f(i,0,m)
        f(j,0,n){
            char c;
            cin>>c;
            if(c=='#') v[j].pb(i);
        }
    f(i,0,n)
        f(j,0,v[i].size()){
            int x,u=T(i,v[i][j]);
            if(j+1<v[i].size())
                Add_edge(u,T(i,v[i][j+1]));
            if(j && v[i][j]==v[i][j-1]+1)
                Add_edge(u,T(i,v[i][j-1]));
            if(i){
                x=i-1;
                if(v[x].size() && v[x][v[x].size()-1]>=v[i][j])
                    Add_edge(u,T(x,*(lower_bound(v[x].begin(),v[x].end(),v[i][j]))));
            }
            x=i+1;
            if(v[x].size() && v[x][v[x].size()-1]>=v[i][j])
                Add_edge(u,T(x,*(lower_bound(v[x].begin(),v[x].end(),v[i][j]))));
        }
    find_strongly();
    f(i,1,c+1){
        ans+=1-in[i];
        //cout<<in[i]<<" ";
    }
    cout<<endl;
    cout<<ans;
}