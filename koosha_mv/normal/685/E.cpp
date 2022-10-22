#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005;

int n,m,q,r[N*N],s[N*N],t[N*N],dist[N][N];
pair<int,int> e[N*N];
bool ans[N*N];
vector<int> query[N*N];

void add(int u,int v){
    f(i,1,n+1){
        if(i!=u && i!=v){
        	minm(dist[u][i],dist[v][i]);
        	minm(dist[v][i],dist[u][i]);
        }
    }
}
int main(){
    f(i,0,N) f(j,0,N) dist[i][j]=N*N;
    cin>>n>>m>>q;
    f(i,0,m){
        Gett(e[i].F,e[i].S);
    }
    f(i,0,q){
        int l;
        Gett(l,r[i]);
        l--;
        Gett(s[i],t[i]);
 
        query[l].pb(i);
    }
    f_(i,m-1,0){
        dist[e[i].F][e[i].S]=i;
        dist[e[i].S][e[i].F]=i;
        add(e[i].F,e[i].S);
        f(j,0,query[i].size()){
            int x=query[i][j];
            ans[x]=(dist[s[x]][t[x]]<r[x]);
        }
    }
    f(i,0,q)
        cout<<(ans[i] ? "Yes" : "No")<<'\n';
}