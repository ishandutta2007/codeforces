#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
#define ERR(...) fprintf(stderr,__VA_ARGS__)
template<class T>inline void cmn(T &x,const T &a){if(a<x)x=a;}
template<class T>inline void cmx(T &x,const T &a){if(x<a)x=a;}
template<class T>inline bool bmn(T &x,const T &a){if(a<x){x=a;return true;}else return false;}
template<class T>inline bool bmx(T &x,const T &a){if(x<a){x=a;return true;}else return false;}

//Fast IO libs.
//This fast IO lib occupies the stdin once a read operation is performed.
namespace IO{
	//Input buffer size. 
	const int l=1<<20;
	//Output buffer size. 
	const int lo=21;
	char buf[l],*s,*t,c;bool f;
	inline void gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			c=s==t?EOF:*s++;
		}else c=*s++;
	}
	//gi(x): Get an integer from stdin and write it to x.
	template<class I>inline void gi(I &x){
		x=0;f=false;gc();while(c<'0'||c>'9'){if(c=='-')f=true;gc();}
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}if(f)x=-x;
	}
	//giu(x): Get a non-positive integer from stdin and write it to x.
	template<class I>inline void giu(I &x){
		x=0;f=false;gc();while(c<'0'||c>'9')gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}if(f)x=-x;
	}
	//gs(x): Get a string from stdin and write the string length to n.
	inline void gs(char *S,int &n){
		n=0;
		gc();while(!isgraph(c))gc();while(isgraph(c)){S[n++]=c;gc();}
	}
	//gch(x): Get a char from stdin.
	inline void gch(char &s){
		gc();while(!isgraph(c))gc();s=c;
	}
	char buf0[lo];int a;
	//pi(x): Put an integer x to stdout.
	//Require: |IntToString(x)| < lo.
	template<class I>inline void pi(I x){
		if(x<0){putchar('-');x=-x;}
		do buf0[++a]=(char(x%10)^'0');while(x/=10);
		while(a)putchar(buf0[a--]);
		putchar('\n');
	}
	//piu(x): Put a non-positive integer x to stdout.
	//Require: |IntToString(x)| < lo.
	template<class I>inline void piu(I x){
		do buf0[++a]=(char(x%10)^'0');while(x/=10);
		while(a)putchar(buf0[a--]);
		putchar('\n');
	}
};
using IO::gi;
using IO::giu;
using IO::gs;
using IO::gch;
using IO::pi;
using IO::piu;

const int MAXN=100005,BS=253;
namespace seg{
	int Cnt,Pos,S[1<<18];
	#define ls o<<1,l,m
	#define rs o<<1|1,m+1,r
	void add(int o,int l,int r){
		++S[o];
		if(l==r){Pos=l;return;}
		int m=(l+r)>>1,Cr=r-m-S[o<<1|1];
		if(Cnt<Cr)add(rs);else{Cnt-=Cr;add(ls);}
	}
	void clr(int o,int l,int r){
		S[o]=0;
		if(l==r)return;
		int m=(l+r)>>1;
		if(Pos<=m)clr(ls);else clr(rs);
	}
};
int Cur,B[MAXN];
struct blk{
	int l,r,n,_,A[BS+1],P[BS+1];
	inline void build(){
		int i;n=0;
		per(i,r,l){
			seg::Cnt=B[i];
			seg::add(1,1,r);
			A[n++]=seg::Pos;
		}
		memcpy(P,A,n<<2);
		sort(P,P+n);
		REP(i,0,n){
			P[i]=(seg::Pos=P[i])-i;
			seg::clr(1,1,r);
		}
	}
	inline void init(const int &_l,const int &_r){
		l=_l;r=_r;build();
	}
	inline void start(const int &i){
		Cur=A[r-i];
	}
	inline void que(){
		Cur+=(upper_bound(P,P+n,Cur)-P);
	}
}K[MAXN/BS+1];

signed main(){
#ifdef ONLINE_JUDGE
	//freopen("problemname.in","r",stdin);
	//freopen("problemname.out","w",stdout);
#endif
	int N;
	giu(N);

	int i;
	rep(i,1,N)giu(B[i]);

	int b=N/BS;
	rep(i,0,b)K[i].init(max(1,i*BS),min(N,i*BS+BS-1));

	int Q;
	giu(Q);

	int o;
	while(Q--){
		giu(o);giu(i);
		if(o==1){
			giu(B[i]);
			K[i/BS].build();
		}else{
			K[o=i/BS].start(i);
			rep(o,o+1,b)K[o].que();
			piu(Cur);
		}
	}
	//ERR("OK\n");
	return 0;
}