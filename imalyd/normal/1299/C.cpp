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
const int N=1000005;
ll a[N],s[N];int j[N],q[N];
inline bool duck(int x,int y,int z){int x1=y-x,x2=z-x;ll y1=s[y]-s[x],y2=s[z]-s[x];return x1*y2<=x2*y1;}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int n,i,l,L,R,M,S;double z;
	scanf("%d",&n);l=n+1;
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	per(i,n,0){
		while(l<n&&duck(i,q[l],q[l+1]))++l;
		q[--l]=i;
//		int jjj;rep(jjj,l,n)printf("q %d ",q[jjj]);puts("");
		L=(S=l)+1;R=n;
		while(L<=R){
			M=(L+R)>>1;
			if(duck(i-1,q[M-1],q[M]))L=(S=M)+1;else R=M-1;
		}
		j[i-1]=q[S];
	}
	for(i=0;i!=n;){
		l=j[i];
		z=((double)(s[l]-s[i]))/(l-i);
		for(;i!=l;++i)printf("%.12lf\n",z);
	}
	return 0;
}