#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
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
int n;
int tall[2000005];
struct segtree{
    int val[8000005];
    int n;
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        
        REP(i,n_) val[i+n-1]=tall[i];
        REPN(i,n,n_) val[i+n-1]=INF;
        for(int i=n-2;i>=0;--i) val[i]=max(val[i*2+1],val[i*2+2]);
    }
    int Lquery(int a,int b,int i,int l,int r,int v){
        if(val[i]<=v) return INF;
        if(r<=a || b<=l) return INF;
        if(r-l==1) return l;
        int md=(l+r)>>1,tmp;
        tmp=Lquery(a,b,i*2+2,md,r,v);
        if(tmp<INF) return tmp;
        return Lquery(a,b,i*2+1,l,md,v);
    }
    int Rquery(int a,int b,int i,int l,int r,int v){
        if(val[i]<=v || r<=a || b<=l) return INF;
        if(r-l==1) return l;
        int md=(l+r)>>1,tmp;
        tmp=Rquery(a,b,i*2+1,l,md,v);
        if(tmp<INF) return tmp;
        return Rquery(a,b,i*2+2,md,r,v);
    }
};
segtree seg;
vector<int> ar[1000005];
int zip[1000005],rank[1000005],cnt[1000005];
struct uf{
    int par[1000000],size[1000005];
    uf(){
        memset(par,-1,sizeof(par));
        REP(i,1000005) size[i]=1;
    }
    int root(int a){
        if(par[a]==-1) return a;
        return par[a]=root(par[a]);
    }
    void unite(int a,int b){
        a=root(a);b=root(b);
        if(a==b) return;
        par[a]=b;
        size[b]+=size[a];
    }
};
uf u;
int main(){
    scanf("%d",&n);
    REP(i,n) scanf("%d",&tall[i]),zip[i]=tall[i];
    sort(zip,zip+n);
    int zn=unique(zip,zip+n)-zip;
    REP(i,n){
        tall[i]=tall[i+n]=lower_bound(zip,zip+zn,tall[i])-zip;
        rank[i]=ar[tall[i]].size();
        ar[tall[i]].pb(i);
    }
    lint res=0,res2=0;
    seg.init(n*2);
    REP(i,zn){
        int prev=ar[i].size();
        ar[i].pb(ar[i][0]+n);
        REP(j,prev){
            int a=seg.Lquery(ar[i][j]+1,ar[i][j+1],0,0,seg.n,i);
            if(a==INF) u.unite(ar[i][j],(ar[i][j+1])%n);
        }
        REP(j,prev) if(u.root(ar[i][j])==ar[i][j]){
            res2+=u.size[ar[i][j]]*(lint)(u.size[ar[i][j]]-1)/2;
        }
    }
    REP(i,n){
        int r=seg.Rquery(i+1,n*2,0,0,seg.n,tall[i]),
            l=seg.Lquery(0,i+n,0,0,seg.n,tall[i]);
        if(l==INF) l=-INF;
        if(r==INF || r>=n*2){
            if(l!=-INF) ++res;
        }else if(l==-INF){
            ++res;
        }else{
            if(l%n==r%n) ++res;
            else res+=2;
        }
    }
    cout<<res+res2<<endl;
        
    return 0;
}