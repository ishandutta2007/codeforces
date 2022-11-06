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
const ll zjc=1000000007ll;
const int N=100005,M=374;
vector<pii>tr[M+5];
vector<vector<int> >st;
vector<int>ts;
int hx[2][4][8][16][32];ll pd[M+5],dp[M+5];
int cnt[32],xxj[5],z;
inline void upd(int v,int u,int w){pd[v]=(pd[v]+dp[u]*w)%1000000007ll;}
inline void init(int l,int t){
	if(l==5){
		hx[xxj[0]][xxj[1]][xxj[2]][xxj[3]][xxj[4]]=++z;
//		printf("z=%d (%d,%d,%d,%d,%d)\n",z,xxj[0],xxj[1],xxj[2],xxj[3],xxj[4]);
		ts.clear();
		ts.pb(xxj[0]);
		ts.pb(xxj[1]);
		ts.pb(xxj[2]);
		ts.pb(xxj[3]);
		ts.pb(xxj[4]);
		st.pb(ts);
		return;
	}
	xxj[l]=0;init(l+1,t);
	int i;
	REP(i,1<<l,2<<l)if(!(i&t)){xxj[l]=i;init(l+1,t|(1<<l));}
}
inline void A(int a){
	int i;
	per(i,4,0)if(a>>i&1){
		if(xxj[i])a^=xxj[i];
		else{xxj[i]=a;return;}
	}
	z=0;
}
inline void A2(int a){
	if(cnt[a])cnt[a]=0;else{cnt[a]=1;A(a);}
}
/*
inline bool Q(int a){
//	printf("Q %d\n",a);
	if(!a)return false;
	int i;
	per(i,4,0)if((a>>i&1)&&!(a^=xxj[i]))return false;
//	printf("T\n");
	return true;
}*/
inline int H(){
	int i,j;
	per(i,4,1)per(j,i-1,0)if(xxj[i]>>j&1)xxj[i]^=xxj[j];
	return hx[xxj[0]][xxj[1]][xxj[2]][xxj[3]][xxj[4]];
}
inline void init2(){
	int i,j,k;
	rep(i,1,M)rep(j,1,M){
		z=1;
		rep(k,0,4)xxj[k]=st[i][k];
		rep(k,0,4)if(st[j][k])A(st[j][k]);
//		if(z&&i==364)printf("%d + %d -> %d\n",i,j,H());
		if(z)tr[i].pb(mp(j,H()));
	}
}
vector<pii>e[N];
pii e2[N];
int e1[N],f[N],d[N];
pair<pii,int> E[N];
inline void dfs(int v,int fa){
	f[v]=2;//printf("vis %d %d fa=%d\n",v,f[v],fa);
	int s=e[v].size(),u;
	while(s--)if((u=e[v][s].fi)!=fa){
//		printf("s=%d u=%d fu=%d\n",s,u,f[u]);
		if(f[u]==2)A2(d[u]^d[v]^e[v][s].se);
		else{
			d[u]=d[v]^e[v][s].se;
			dfs(u,v);
		}
	}
}
int main(){
//	freopen("d1.in","r",stdin);
//	freopen("d.out","w",stdout);
	ts.pb(0);
	ts.pb(0);
	ts.pb(0);
	ts.pb(0);
	ts.pb(0);
	st.pb(ts);
	init(0,0);
	init2();
	int n,m,i=0,v,u,w;ll ans=0ll;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&v,&u,&w);
		if(u==1)swap(v,u);
		if(v==1){f[u]=1;e1[u]=w;}
		else E[++i]=mp(mp(v,u),w);
	}
	rep(m,1,i){
		v=E[m].fi.fi;
		u=E[m].fi.se;
		w=E[m].se   ;
		if(f[v]&&f[u]){
			e2[v]=mp(u,w);
			e2[u]=mp(v,w);
		}
//		printf("v=%d u=%d w=%d\n",v,u,w);
		e[v].pb(mp(u,w));
		e[u].pb(mp(v,w));
	}
//	rep(v,2,n){REP(i,0,e[v].size())printf("(%d,%d)",e[v][i].fi,e[v][i].se);puts("");}
	dp[1]=1ll;
	rep(v,2,n)if(f[v]==1){
		rep(i,0,4)xxj[i]=0;
		z=1;
		dfs(v,0);
//		printf("z=%d\n",z);
		rep(i,1,M)pd[i]=dp[i];
		if(u=e2[v].fi){
//			printf("v=%d u=%d w=%d\n",v,u,e1[v]^e1[u]^e2[v].se);
			if(z){
				w=H();
//				printf("add v=%d u=%d h=%d\n",v,u,w);
				i=tr[w].size();
				while(i--)upd(tr[w][i].se,tr[w][i].fi,2);
				A(e1[v]^e1[u]^e2[v].se);
				if(z){
					w=H();
//					printf("add v=%d u=%d h=%d\n",v,u,w);
					i=tr[w].size();
					while(i--)upd(tr[w][i].se,tr[w][i].fi,1);
				}
			}
		}else{
//			printf("v=%d\n",v);
			if(z){
				w=H();
//				printf("add v=%d h=%d\n",v,w);
				i=tr[w].size();
				while(i--)upd(tr[w][i].se,tr[w][i].fi,1);
			}
		}
		rep(i,1,M)dp[i]=pd[i];
	}
	rep(i,1,M)ans+=dp[i];
	printf("%lld",ans%1000000007ll);
	return 0;
}