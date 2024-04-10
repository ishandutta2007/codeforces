#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int table[100005];
int prime[100005];
int limit[100005];
int n,m;
vector<int> g[100005],rg[100005];
int mpow(int a,int k){
    int res=1;
    while(k){
        if(k&1) res=res*a;
        a=a*a;
        k>>=1;
    }
    return res;
}
int col[100005];
int K;
int gcd;
void dfs(int v){
    REP(i,g[v].size()){
        int to=g[v][i];
        if(col[to]==-1){
            col[to]=col[v]+1;
            dfs(to);
        }else if(abs(col[to]-col[v]-1)!=0){
            if(gcd==-1) gcd=abs(col[to]-col[v]-1);
            else gcd=__gcd(gcd,abs(col[to]-col[v]-1));
        }
    }
    REP(i,rg[v].size()){
        int to=rg[v][i];
        if(col[to]==-1){
            col[to]=col[v]-1;
            dfs(to);
        }else if(abs(col[to]-col[v]+1)!=0){
            if(gcd==-1) gcd=abs(col[to]-col[v]+1);
            else gcd=__gcd(gcd,abs(col[to]-col[v]+1));
        }
    }
}

int check(int k){
    K=k;
    gcd=-1;
    memset(col,-1,sizeof(col));
    REP(i,n) if(col[i]==-1){
        col[i]=2*K;
        dfs(i);
    }
    if(gcd==-1) gcd=k;
    return gcd;
}
pi factor[30];
int main(){
    scanf("%d%d",&n,&m);
    REP(i,m){
        int a,b;scanf("%d%d",&a,&b);--a;--b;
        g[a].pb(b);
        rg[b].pb(a);
    }
    printf("%d\n",check(n));
    return 0;
}