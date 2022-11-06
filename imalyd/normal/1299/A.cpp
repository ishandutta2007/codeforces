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
const int N=100005;
int a[N],p[N],s[N];
inline int f(int a,int b){return (a|b)^b;}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int n,i,mx,id=1,t;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	REP(i,1,n)p[i]=p[i-1]|a[i];
	per(i,n,2)s[i]=s[i+1]|a[i];
	mx=f(a[1],s[2]);
	rep(i,2,n)if((t=f(a[i],p[i-1]|s[i+1]))>mx){mx=t;id=i;}
	swap(a[1],a[id]);
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}