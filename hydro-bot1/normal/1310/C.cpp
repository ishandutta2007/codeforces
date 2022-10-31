// Hydro submission #62824d820a6a2572e8babcde@1652706691457
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

#define modPrepare() \
void Add(int &x,int y){(x+=y)>=Mod?x-=Mod:x;}\
void Del(int &x,int y){(x-=y)<0?x+=Mod:x;}\
int Pow(int a,int b){\
	int res=1;\
	while(b){\
		if(b&1) res=1ll*res*a%Mod;\
		a=1ll*a*a%Mod,b>>=1;\
	}\
	return res;\
}

#define facPrepare(_) \
const int len=_;\
int Fac[len+10],Iac[len+10]; \
void facInit(){\
	Fac[0]=Iac[0]=1;\
	for(int i=1;i<=len;++i) Fac[i]=1ll*Fac[i-1]*i%Mod;\
	Iac[len]=Pow(Fac[len],Mod-2);\
	for(int i=len-1;i;--i) Iac[i]=1ll*Iac[i+1]*(i+1)%Mod;\
}\
int Binom(int x,int y){return x<y?0:1ll*Fac[x]*Iac[y]%Mod*Iac[x-y]%Mod;}

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

void read(int& x){
    static char c;int f=0;
    while(!isdigit(c=getchar()))
        if(c=='-') f=1;
    x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
    if(f) x=-x;
}
void read(ll& x){
    static char c;int f=0;
    while(!isdigit(c=getchar()))
    	if(c=='-') f=1;
    x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
    if(f) x=-x;
}
void read(uint& x){
    static char c;
    while(!isdigit(c=getchar()));x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
}
void read(ull& x){
    static char c;
    while(!isdigit(c=getchar()));x=c^48;
    while(isdigit(c=getchar())) x=(x*10)+(c^48);
}
void chkmax(int& x,int y){if(y>x)x=y;}
void chkmin(int& x,int y){if(y<x)x=y;}
void chkmax(ll& x,ll y){if(y>x)x=y;}
void chkmin(ll& x,ll y){if(y<x)x=y;}
void chkmax(uint& x,uint y){if(y>x)x=y;}
void chkmin(uint& x,uint y){if(y<x)x=y;}
void chkmax(ull& x,ull y){if(y>x)x=y;}
void chkmin(ull& x,ull y){if(y<x)x=y;}

const int N=1e3+10;
const ll Inf=1e18;

int n,m;
ll k;
char str[N];

struct BigNum{
	ll v;
	BigNum(){v=0ll;}
	BigNum(ll _v):v(_v){}
	BigNum operator+=(BigNum x){
		if(v==-1||x.v==-1) return *this=BigNum(-1ll);
		if(ull(v+x.v)>ull(Inf)) return *this=BigNum(-1ll);
		return *this=BigNum(v+x.v);
	}
	bool operator<(ll k){
		if(v==-1) return false;
		return v<k;
	}
};

int rk[N][N],tot;
pii id[N*N];
namespace Sort{
	int _rk[N],sa[N];
	void buildSuffixArray(){
		iota(sa,sa+n+1,0);
		sort(sa+1,sa+n+1,[&](int x,int y)->bool{
			int l=0;
			while(x+l<=n&&y+l<=n)
				if(str[x+l]==str[y+l]) ++l;
				else break;
			if(x+l>n) return true;
			if(y+l>n) return false;
			return str[x+l]<str[y+l];
		});
		for(int i=1;i<=n;++i) _rk[sa[i]]=i;
	}
	
	int h[N],_min[N][N];
	void buildSparseTable(){
		for(int i=2;i<=n;++i)
			while(str[sa[i]+h[i]]==str[sa[i-1]+h[i]]) ++h[i];
		for(int l=2;l<=n;++l){
			_min[l][l]=h[l];
			for(int r=l+1;r<=n;++r)
				_min[l][r]=min(_min[l][r-1],h[r]);
		}
	}
	int getlcp(int i,int j){
		if(i==j) return n-i+1;
		if(_rk[i]>_rk[j]) swap(i,j);
		return _min[_rk[i]+1][_rk[j]];
	}
	
	void substringSort(){
		buildSuffixArray();
		buildSparseTable();
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j) id[++tot]=mp(i,j);
		sort(id+1,id+tot+1,[&](pii x,pii y)->bool{
			int lcp=getlcp(x.fir,y.fir);
			if(lcp>=min(x.sec-x.fir,y.sec-y.fir)+1) return x.sec-x.fir<y.sec-y.fir;
			else return str[x.fir+lcp]<str[y.fir+lcp];
		});
		for(int i=1;i<=tot;++i) rk[id[i].fir][id[i].sec]=i;
	}
}

bool chk(int R){
	vector<vector<BigNum>> f(n+1),tag(n+1);
	for(int i=0;i<=n;++i)
		f[i].resize(m+1),tag[i].resize(m+1);
	f[0][0]=BigNum(1ll);
	for(int i=0;i<=n;++i){
		int l=i+1,r=n,mid,rig=n+1;
		while(l<=r){
			mid=(l+r)>>1;
			if(rk[i+1][mid]>=R) rig=mid,r=mid-1;
			else l=mid+1;
		}
		if(i)
			for(int j=1;j<=m;++j)
				f[i][j]=(tag[i][j]+=tag[i-1][j]);
		if(rig<=n)
			for(int j=0;j<m;++j)
				tag[rig][j+1]+=f[i][j];
	}
	return f[n][m]<k;
}

void Work(){
	read(n),read(m),read(k);
	scanf("%s",str+1);
	Sort::substringSort();
	int l=1,r=tot,mid,res=tot+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	--res;
	l=id[res].fir,r=id[res].sec;
	for(int i=l;i<=r;++i) putchar(str[i]);putchar('\n');
}

int main(){Work();}