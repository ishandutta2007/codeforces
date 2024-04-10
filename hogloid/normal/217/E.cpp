#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
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
char s[3000005];
int k,n;
pi query[5005];
struct segtree{
    int n;
    int val[8388610];
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        REP(i,n_) val[i+n-1]=1;
        for(int i=n-2;i>=0;--i) val[i]=val[i*2+1]+val[i*2+2];
    }
    int query(int i,int l,int r,int k){
        if(val[i]<=k) return INF;
        while(1){
            if(r-l==1) return l;
            int md=(l+r)>>1;
            if(val[i*2+1]>k){
                r=md;
                i=i*2+1;
            }else{
                k-=val[i*2+1];
                l=md;
                i=i*2+2;
            }
        }
    }
    int query2(int b,int i,int l,int r){
        if(r<=b) return val[i];
        if(b<=l) return 0;
        int md=(l+r)>>1;
        return query2(b,i*2+1,l,md)+query2(b,i*2+2,md,r);
    }
    void del(int k){
        k+=n-1;
        val[k]=0;
        while(k>0){
            k=(k-1)/2;
            val[k]=val[k*2+1]+val[k*2+2];
        }
    }
};
struct uf{
    int par[3000005];
    void init(){
        REP(i,k) par[i]=-1;
    }
    int root(int a){
        if(par[a]==-1) return a;
        return par[a]=root(par[a]);
    }
    void unite(int a,int b){
        par[b]=a;
    }
};
uf u;
segtree seg;
char res[3000005];
int main(){
    scanf("%s%d%d",s,&k,&n);
    int len=strlen(s);
    REP(i,n){
        scanf("%d%d",&query[i].fr,&query[i].sc);--query[i].fr;
        int tmp=query[i].sc-query[i].fr;
        query[i].fr+=tmp;
        query[i].sc+=tmp;
    }
    seg.init(k);
    u.init();
    for(int i=n-1;i>=0;--i){
        int back=query[i].fr-(query[i].sc-query[i].fr),
            half=(query[i].sc-query[i].fr)/2;
        pi range;range.fr=query[i].fr;range.sc=-1;
        for(int j=query[i].fr;j<query[i].sc;++j){
            int p=seg.query(0,0,seg.n,j);
            if(p>=INF) break;
            int orig;
            if((j-query[i].fr)<half){
                orig=back+1+(j-query[i].fr)*2;
            }else{
                int p2=(j-query[i].fr)-half;
                orig=back+p2*2;
            }
            orig=seg.query(0,0,seg.n,orig);
            u.unite(orig,p);
            range.sc=j;
        }
        for(int j=range.sc;j>=range.fr;--j) seg.del(seg.query(0,0,seg.n,j));
    }
    REP(i,k){
        int r=u.root(i);
        res[i]=s[seg.query2(r+1,0,0,seg.n)-1];
    }
    printf("%s\n",res);
    
    return 0;
}