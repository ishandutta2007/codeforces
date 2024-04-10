// Hydro submission #62c6d4688672efa577c02093@1657197673313
#include<bits/stdc++.h>
#define inl inline
#define re(i,x,y) for(int i=(x);i<(y);++i) 
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define repp(i,x,y,d) for(int i=(x);i<=(y);i+=(d))
#define reep(i,x,y) for(int i=(x);i<=(y);i<<=1)
#define pe(i,x,y) for(int i=(x)-1;i>=(y);--i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define rep_e(i,u) for(int i=head[(u)];i;i=E[i].nxt)
#define vi vector<int>
#define vL vector<LL>
#define vii vector<pii> 
#define viL vector<piL>
#define vLi vector<pLi> 
#define vLL vector<pLL>
#define viii vector<tiii>
#define viiL vector<tiiL>
#define viLi vector<tiLi>
#define vLii vector<tLii>
#define viLL vector<tiLL>
#define vLiL vector<tLiL>
#define vLLi vector<tLLi> 
#define vLLL vector<tLLL>
#define eb emplace_back
#define pb pop_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define piL pair<int,LL>
#define pLi pair<LL,int>
#define pLL pair<LL,LL>
#define pdi pair<db,int>
#define pdd pair<db,db>
#define pid pair<int,db> 
#define tiii tuple<int,int,int>
#define tiiL tuple<int,int,LL>
#define tiLi tuple<int,LL,int>
#define tLii tuple<LL,int,int>
#define tiLL tuple<int,LL,LL>
#define tLiL tuple<LL,int,LL>
#define tLLi tuple<LL,LL,int>
#define tLLL tuple<LL,LL,LL>
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define debug(x) cout<<#x<<" = "<<x<<endl
using namespace std;
typedef unsigned int ui;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
#define getchar() (SB==TB&&(TB=(SB=BB)+fread(BB,1,1<<15,stdin),SB==TB)?EOF:*SB++)
char BB[1<<16],*SB=BB,*TB=BB;
template<typename T>void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inl void chkmn(T &a,const T &b){ (a>b)&&(a=b); }
template<typename T>inl void chkmx(T &a,const T &b){ (a<b)&&(a=b); }
inl int min(const int &a,const int &b){ return a<b?a:b; }
inl int max(const int &a,const int &b){ return a>b?a:b; }
inl LL min(const LL &a,const LL &b){ return a<b?a:b; }
inl LL max(const LL &a,const LL &b){ return a>b?a:b; }

int MOD;
inl int adt(const int &a){ return (a%MOD+MOD)%MOD; } 
inl int inc(const int &a,const int &b){ return a+b>=MOD?a+b-MOD:a+b; }
inl int dec(const int &a,const int &b){ return a-b<0?a-b+MOD:a-b; }
inl int mul(const int &a,const int &b){ return 1LL*a*b%MOD; }
inl int sqr(const int &a){ return 1LL*a*a%MOD; }
inl void Adt(int &a){ a=(a%MOD+MOD)%MOD; } 
inl void Inc(int &a,const int &b){ ((a+=b)>=MOD)&&(a-=MOD); }
inl void Dec(int &a,const int &b){ ((a-=b)<0)&&(a+=MOD); }
inl void Mul(int &a,const int &b){ a=1LL*a*b%MOD; }
inl void Sqr(int &a){ a=1LL*a*a%MOD; }
inl int fsp(int a,int x=MOD-2){
	int res=1;
	while(x){
		if(x&1) Mul(res,a);
		Sqr(a),x>>=1;
	}return res;
}

const int maxn=2e5+1;
int n,q;
int a[maxn];
struct LB{
    int sz,a[30];
    LB(){ sz=0,memset(a,0,sizeof(a)); }
    inl void ins(int x){
        pe(i,30,0) if((x>>i)&1){
            if(!a[i]) return a[i]=x,++sz,void();
            x^=a[i];
        }
    }
};
inl LB Merge(LB A,LB B){
    re(i,0,30) if(B.a[i]) A.ins(B.a[i]);
    return A;
}
namespace SGT{
    #define lc (id<<1)
    #define rc (id<<1|1)
    #define mid ((l+r)>>1)
    LB s[maxn<<2];
    inl void Push_Up(int id){ s[id]=Merge(s[lc],s[rc]); }
    inl void Build(int id=1,int l=1,int r=n){
        if(l==r) return s[id].ins(a[l]),void();
        Build(lc,l,mid),Build(rc,mid+1,r);
        Push_Up(id);
    }
    inl void Update(int x,int v,int id=1,int l=1,int r=n){
        if(x>r) return ;
        if(l==r) return s[id]=LB(),s[id].ins(a[l]^=v),void();
        x<=mid?Update(x,v,lc,l,mid):Update(x,v,rc,mid+1,r);
        Push_Up(id);
    }
    inl LB Query(int x,int y,int id=1,int l=1,int r=n){
        if(y<x) return LB();
        if(x<=l&&r<=y) return s[id];
        if(x>mid) return Query(x,y,rc,mid+1,r);
        if(y<=mid) return Query(x,y,lc,l,mid);
        return Merge(Query(x,y,lc,l,mid),Query(x,y,rc,mid+1,r));
    }
}
namespace BIT{
    int res,C[maxn];
    inl void Update(int x,int v){
        for(;x<=n;x+=lowbit(x))
            C[x]^=v;
    }
    inl int Query(int x){
        for(res=0;x;x-=lowbit(x))
            res^=C[x];
        return res;
    }
}

int main(){
	read(n),read(q);
	rep(i,1,n) read(a[i]);
    per(i,n,1) a[i]^=a[i-1],BIT::Update(i,a[i]);
    SGT::Build();
    int op,l,r,v;
    while(q--){
        read(op),read(l),read(r);
        if(op&1){
            read(v);
            BIT::Update(l,v),BIT::Update(r+1,v),SGT::Update(l,v),SGT::Update(r+1,v);
        }
        else{
            LB t=SGT::Query(l+1,r);
            t.ins(BIT::Query(l));
            printf("%d\n",1<<t.sz);
        }
    }
	return 0;
}