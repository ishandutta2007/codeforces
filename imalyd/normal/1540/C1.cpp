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

const int p=1000000007;
const int ps2=p-2;
inline void add(int &x){if(x>=p)x-=p;}
inline void sub(int &x){if(x< 0)x+=p;}
#define MUL(a,b) ((0ll|(a))*(b)%p)
template<class T>int expo(int a,T b){
	int s(1);
	while(b){if(b&1)s=MUL(s,a);b>>=1;a=MUL(a,a);}
	return s;
}
int expo(int a){
	int b(ps2),s(1);
	while(b){if(b&1)s=MUL(s,a);b>>=1;a=MUL(a,a);}
	return s;
}

const int MAXN=105;
int C[MAXN],B[MAXN],F[MAXN*100];
signed main(){
#ifdef ONLINE_JUDGE
	//freopen("problemname.in","r",stdin);
	//freopen("problemname.out","w",stdout);
#endif
	int N;
	giu(N);

	int i;
	rep(i,1,N)giu(C[i]);
	rep(i,2,N)giu(B[i]);

	giu(i);
	gi(B[1]);

	int Dm=0,Sm=0,T=0,k,c;
	F[0]=1;
	rep(i,1,N){
		c=C[i]+1;
		Sm+=(Dm+=B[i]);
		//ERR("i=%d Sm=%d\n",i,Sm);
		per(k,T-1,0)sub(F[k+c]-=F[k]);
		T+=c-1;
		c=0;
		rep(k,0,T){add(c+=F[k]);F[k]=c;}
		per(k,min(Sm-1,T),0)F[k]=0;
	}
	c=0;
	rep(k,max(0,Sm),T)add(c+=F[k]);
	printf("%d\n",c);
	return 0;
}