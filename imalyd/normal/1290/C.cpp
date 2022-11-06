//https://codeforces.com/contest/1290/problem/C
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
const int N=300005;
struct node{
	int s,f,e,c0,c1;
}a[N];
inline int getf(int &v){
	int w=0;
	while(a[v].f){
		w^=a[v].e;
		v =a[v].f;
	}
	return w;
}
vector<int>e[N];
char c[N];
int main(){
	int n,m,i,v,u,w,ans;
	scanf("%d%d%s",&m,&n,c+1);
	rep(i,1,n){
		scanf("%d",&u);
		while(u--){scanf("%d",&v);e[v].pb(i);}
	}
	rep(i,1,n)a[i].s=a[i].c1=1;
	rep(i,1,m){
		if(e[i].size()){
			w=c[i]^'1';
			if(e[i].size()==1){
				v =e[i][0];
				w^=getf(v);
				ans-=min(a[v].c0,a[v].c1);
				(w?a[v].c0:a[v].c1)=N;
				ans+=min(a[v].c0,a[v].c1);
			}else{
				v =e[i][0];
				u =e[i][1];
				w^=getf(v)^getf(u);
				if(v!=u){
					if(a[v].s<a[u].s)swap(v,u);
					ans-=min(a[v].c0,a[v].c1);
					ans-=min(a[u].c0,a[u].c1);
					if(w)swap(a[u].c0,a[u].c1);
					a[v].s+=a[u].s;
					a[u].f=v;
					a[u].e=w;
					cmin(a[v].c0+=a[u].c0,N);
					cmin(a[v].c1+=a[u].c1,N);
					ans+=min(a[v].c0,a[v].c1);
				}
			}
		}
//		rep(v,1,n)printf("v=%d sz=%d fa=%d c0=%d c1=%d\n",v,a[v].s,a[v].f,a[v].c0,a[v].c1);
		printf("%d\n",ans);
	}
	return 0;
}