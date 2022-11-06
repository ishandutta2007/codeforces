//https://codeforces.com/contest/1290/problem/D
#include<bits/stdc++.h>
using namespace std;
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t,c;
	inline void gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			c=s==t?EOF:*s++;
		}else c=*s++;
	}
	template<class IT>inline void gi(IT &x){
		x=0;gc();while(c<'0'||c>'9')gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}
	}
	char buf0[20];int a;
	template<class IT>inline void pi(IT x){
		if(x<0){putchar('-');x=-x;}
		do buf0[++a]=x%10+48;while(x/=10);
		while(a)putchar(buf0[a--]);
		putchar('\n');
	}
};
using io::gi;
using io::pi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll > pil;
typedef pair<ll ,int> pli;
typedef pair<ll ,ll > pll;
#define pque priority_queue
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
const int N=1024;
bool vis[N];char c[2];
inline bool Q(int v){printf("? %d\n",v+1);fflush(stdout);scanf("%s",c);return c[0]=='Y';}
inline void V(int v){if(vis[v]&&Q(v))vis[v]=false;}
inline void R(){puts("R");fflush(stdout);}
inline void A(int v){printf("! %d\n",v  );fflush(stdout);}
int main(){
	int n,k,m,m1,m2,d=0,i,j,l,t;
	scanf("%d%d",&n,&k);
	m=n;
	if(k!=1){
		for(i=k>>=1;i!=1;i>>=1){m>>=1;++d;}
	}
	m1=m-1;m2=m>>1;
	REP(i,0,n)vis[i]=true;
	REP(i,0,m2){
		REP(j,0,k)V(i<<d|j);
		REP(l,1,m2){
			t=(i-l+m)&m1;REP(j,0,k)V(t<<d|j);
			t=(i+l  )&m1;REP(j,0,k)V(t<<d|j);
		}
		t=i^m2;
		REP(j,0,k)V(t<<d|j);
		R();
	}
	t=0;
	REP(i,0,n)if(vis[i])++t;
	A(t);
	return 0;
}