#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli __builtin_popcountll
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
db inf = 1e60;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n,t,q;
int pi[222222];
int li[222222];
int wo[222222];

inline db vp(int i){
	if((wo[i]+1)>li[i])return -inf;
	return db(pi[i])*li[i]/(1+wo[i]+li[i])/(wo[i]+li[i]);
}
inline db vm(int i){
	if(wo[i]==0)return -inf;
	return -db(pi[i])*li[i]/(-1+wo[i]+li[i])/(wo[i]+li[i]);
}

class cmpplu{
	public:
		bool operator()(int i,int j){
			db x=vp(i);
			db y=vp(j);
			if(x!=y)return x>y;
			return i<j;
		}
};
class cmpminu{
	public:
		bool operator()(int i,int j){
			db x=vm(i);
			db y=vm(j);
			if(x!=y)return x>y;
			return i<j;
		}
};

db su=0.0;
multiset<int,cmpplu> mp;
multiset<int,cmpminu> mm;


int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(t);gn(q);
	rep(i,1,n+1)gn(pi[i]);
	rep(i,1,n+1)gn(li[i]);

	/*rep(i,1,n+1){
		plu[i]=1.0/(1.0+li[i])*pi[i];
		minu[i]=-inf;
	}*/
	rep(i,1,n+1){
		mp.insert(i);
		mm.insert(i);
	}


	while(t){
		int id=*mp.begin();
		if(wo[id]==li[id])break;
		mp.erase(id);
		mm.erase(id);
		su+=vp(id);
		wo[id]++;
		t--;
		mp.insert(id);
		mm.insert(id);
	}

	while(q--){
		int opt,id;
		gn(opt);gn(id);
		mp.erase(id);
		mm.erase(id);
		su-=db(wo[id])/(wo[id]+li[id])*pi[id];
		if(opt==1){
			li[id]++;
			su+=db(wo[id])/(wo[id]+li[id])*pi[id];

			while(t && wo[id]<li[id]){
				su+=vp(id);
				wo[id]++;
				t--;
			}
		}else{
			li[id]--;
			su+=db(wo[id])/(wo[id]+li[id])*pi[id];

			while(wo[id]>li[id]){
				su+=vm(id);
				wo[id]--;
				t++;
			}
		}
		mm.insert(id);
		mp.insert(id);

		while(t){
			int id=*mp.begin();
			if(wo[id]==li[id])break;
			mp.erase(id);
			mm.erase(id);
			su+=vp(id);
			wo[id]++;
			t--;
			mp.insert(id);
			mm.insert(id);
		}

		while(1){
			int id1=*mp.begin(),id2=*mm.begin();
			db f1=vp(id1),f2=vm(id2);
			if(f1+f2>1e-12){
				mp.erase(id1);
				mm.erase(id1);
				mp.erase(id2);
				mm.erase(id2);

				su+=f1+f2;
				wo[id2]--;
				wo[id1]++;

				mp.insert(id1);
				mm.insert(id1);
				mp.insert(id2);
				mm.insert(id2);

			}else break;
		}
		printf("%.15lf\n",double(su));
	}



	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}