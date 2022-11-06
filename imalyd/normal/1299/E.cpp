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
const int N=200005;
pair<pii,pii> md[N];
int ans[N],p[N],vis[N];
vector<int>q;
int pl[5],pr[5];
const int perm[2][20]={{0,2,1,3,4},{0,9,6,1,4,2,10,5,8,7,3}},mode=1;
inline int gs(){
	int s=q.size(),t=0;
	while(s--)t+=perm[mode][q[s]];
	return !(t%q.size());
}
inline int Q(){
	int s=q.size();
	printf("? %d",s);
	while(s--)printf(" %d",q[s]);
	printf("\n");
	fflush(stdout);
	//s=gs();printf("%d\n",s);
	scanf("%d",&s);
	return s;
}
inline void A(int n){
	int i;
	if((ans[1]<<1)>n)rep(i,1,n)ans[i]=n+1-ans[i];
	printf("!");
	rep(i,1,n)printf(" %d",ans[i]);
	printf("\n");
	fflush(stdout);
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n,i,j,k,p1=0,pn=0,p2,pm;pair<pii,pii>MD;
	scanf("%d",&n);

	rep(i,1,n){
		q.clear();
		rep(j,1,n)if(j!=i)q.pb(j);
		if(Q()){if(p1)pn=i;else p1=i;}
	}
	vis[pl[1]=p1]=vis[pr[1]=pn]=1;
	//printf("p1=%d pn=%d\n",p1,pn);

	rep(i,1,n)if(!vis[i]){
		q.clear();
		q.pb(p1);
		q.pb(i );
		p[i]=Q();
	}
	//rep(i,1,n)printf("%d ",p[i]);printf("Parity\n");

	rep(k,2,4){
		if((k-1)==(n>>1)){
			REP(i,1,k)ans[pl[i]]=    i;
			REP(i,1,k)ans[pr[i]]=n+1-i;
			A(n);return 0;
		}
		p2=pm=0;
		rep(i,1,n)if(!vis[i]){
			q.clear();
			rep(j,1,n)if(!vis[j]&&j!=i)q.pb(j);
			if(Q()){if(p2)pm=i;else p2=i;}
		}
		if(p[p2]!=(k&1))swap(p2,pm);
		vis[pl[k]=p2]=vis[pr[k]=pm]=1;
		//printf("p2=%d pm=%d\n",p2,pm);
	}

	rep(i,1,n)if(!vis[i]){
		q.clear();q.pb(pl[2]);q.pb(pl[3]);q.pb(i);
		if(Q())md[i].fi.fi=1;
	}
	rep(i,1,n)if(!vis[i])if(!md[i].fi.fi){
		q.clear();q.pb(pl[1]);q.pb(pl[3]);q.pb(i);
		if(Q())md[i].fi.fi=2;
	}
	//rep(i,1,n)printf("%d ",md[i].fi.fi);printf("Mod 3\n");

	rep(i,1,n)if(!vis[i])md[i].fi.se=-1;
	k=((n<<2)+1)%5;
	rep(i,1,n)if(!vis[i]){
		q.clear();q.pb(pl[2]);q.pb(pl[3]);q.pb(pl[4]);q.pb(pn);q.pb(i);
		if(Q())md[i].fi.se=k;
	}
	k=((n<<2)+2)%5;
	rep(i,1,n)if(!vis[i])if(!(~md[i].fi.se)){
		q.clear();q.pb(pl[1]);q.pb(pl[3]);q.pb(pl[4]);q.pb(pn);q.pb(i);
		if(Q())md[i].fi.se=k;
	}
	k=((n<<2)+3)%5;
	rep(i,1,n)if(!vis[i])if(!(~md[i].fi.se)){
		q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[4]);q.pb(pn);q.pb(i);
		if(Q())md[i].fi.se=k;
	}
	k=((n<<2)+4)%5;
	rep(i,1,n)if(!vis[i])if(!(~md[i].fi.se)){
		q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[3]);q.pb(pn);q.pb(i);
		if(Q())md[i].fi.se=k;
	}
	k=(n<<2)%5;
	rep(i,1,n)if(!vis[i])if(!(~md[i].fi.se))md[i].fi.se=k;
	//rep(i,1,n)printf("%d ",md[i].fi.se);printf("Mod 5\n");

	rep(i,1,n)if(!vis[i])md[i].se.fi=-1;
	k=((n<<2)+6)%7;
	rep(i,1,n)if(!vis[i]){
		q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[3]);
		q.pb(i);  q.pb(pr[4]);q.pb(pr[3]);q.pb(pr[1]);
		if(Q())md[i].se.fi=k;
	}
	k=((n<<2)+5)%7;
	rep(i,1,n)if(!vis[i])if(!(~md[i].se.fi)){
		q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[3]);
		q.pb(i);  q.pb(pr[4]);q.pb(pr[2]);q.pb(pr[1]);
		if(Q())md[i].se.fi=k;
	}
	k=((n<<2)+4)%7;
	rep(i,1,n)if(!vis[i])if(!(~md[i].se.fi)){
		q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[3]);
		q.pb(i);  q.pb(pr[3]);q.pb(pr[2]);q.pb(pr[1]);
		if(Q())md[i].se.fi=k;
	}
	k=((n<<2)+3)%7;
	rep(i,1,n)if(!vis[i])if(!(~md[i].se.fi)){
		q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[4]);
		q.pb(i);  q.pb(pr[3]);q.pb(pr[2]);q.pb(pr[1]);
		if(Q())md[i].se.fi=k;
	}
	k=((n<<2)+2)%7;
	rep(i,1,n)if(!vis[i])if(!(~md[i].se.fi)){
		q.clear();q.pb(pl[1]);q.pb(pl[3]);q.pb(pl[4]);
		q.pb(i);  q.pb(pr[3]);q.pb(pr[2]);q.pb(pr[1]);
		if(Q())md[i].se.fi=k;
	}
	k=((n<<2)+1)%7;
	rep(i,1,n)if(!vis[i])if(!(~md[i].se.fi)){
		q.clear();q.pb(pl[2]);q.pb(pl[3]);q.pb(pl[4]);
		q.pb(i);  q.pb(pr[3]);q.pb(pr[2]);q.pb(pr[1]);
		if(Q())md[i].se.fi=k;
	}
	k=(n<<2)%7;
	rep(i,1,n)if(!vis[i])if(!(~md[i].se.fi))md[i].se.fi=k;
	//rep(i,1,n)printf("%d ",md[i].se.fi);printf("Mod 7\n");

	rep(i,1,n)if(!vis[i]){
		if(p[i]){
			q.clear();q.pb(pl[2]);q.pb(pl[3]);q.pb(pl[4]);q.pb(i);
			if(Q()){
				q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[4]);
				q.pb(i)  ;q.pb(pr[1]);q.pb(pr[2]);q.pb(pr[3]);q.pb(pr[4]);
				md[i].se.se=Q()?7:3;
			}else{
				q.clear();q.pb(pl[2]);q.pb(pl[3]);q.pb(pl[4]);
				q.pb(i)  ;q.pb(pr[1]);q.pb(pr[2]);q.pb(pr[3]);q.pb(pr[4]);
				md[i].se.se=Q()?5:1;
			}
		}else{
			q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[3]);q.pb(i);
			if(Q()){
				q.clear();q.pb(pl[1]);q.pb(pl[3]);q.pb(pl[4]);
				q.pb(i)  ;q.pb(pr[1]);q.pb(pr[2]);q.pb(pr[3]);q.pb(pr[4]);
				md[i].se.se=Q()?6:2;
			}else{
				q.clear();q.pb(pl[1]);q.pb(pl[2]);q.pb(pl[3]);
				q.pb(i)  ;q.pb(pr[1]);q.pb(pr[2]);q.pb(pr[3]);q.pb(pr[4]);
				md[i].se.se=Q()?0:4;
			}
		}
	}
	//rep(i,1,n)printf("%d ",md[i].se.se);printf("Mod 8\n");
	rep(i,1,n)if(!vis[i]){
		MD=md[i];
		rep(k,1,n)if(k%3==MD.fi.fi&&k%5==MD.fi.se&&k%7==MD.se.fi&&(k&7)==MD.se.se){
			ans[i]=k;break;
		}
	}
	rep(i,1,4)ans[pl[i]]=    i;
	rep(i,1,4)ans[pr[i]]=n+1-i;
	A(n);
	return 0;
}