#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define fo(i,a,b)for(int i=a,E=b;i<=E;++i)
#define fd(i,a,b)for(int i=b,E=a;i>=E;--i)
#define abs(x)(x>0?x:-(x))
#define ll long long
using namespace std;
const int N=1e5+5,M=1300;
int n,m,sn,js,p[N],la[N],ne[N],b[N];
int df,dn[N],d[N],ld[N],hv[N],q[M],qs,ans;
int a[N],st[M*2],ss,vi[M*2],vs,f[N],gs,cnt[N];
int cs,be[N],en[N],w[N];
struct no{
	int x,y;
	no(int _x,int _y){x=_x;y=_y;}
	no(){}
}aa[N],c[N];
bool op[N];
void dfs(int x){
	d[x]=d[p[x]]+1;ld[x]=1;dn[x]=++df;
	for(int i=la[x];i;i=ne[i])dfs(i),ld[x]+=ld[i],(ld[i]>ld[hv[x]]?hv[x]=i:0);
}
void df2(int x,int st){
	ld[x]=st;
	if(!hv[x])return;
	df2(hv[x],st);
	for(int i=la[x];i;i=ne[i])if(i!=hv[x])df2(i,i);
}
int lca(int x,int y){
	for(;ld[x]!=ld[y];x=p[ld[x]])if(d[ld[x]]<d[ld[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
bool cmp(int x,int y){return dn[x]<dn[y];}
void build(){
	fo(i,1,qs)a[i]=abs(q[i]);
	sort(a+1,a+qs+1,cmp);
	st[ss=1]=vi[vs=1]=1;
	fo(i,1,qs){
		int lc=lca(st[ss],a[i]);
		if(lc==st[ss]){
			if(st[ss]!=a[i])st[++ss]=vi[++vs]=a[i];
			continue;
		}
		for(;d[st[ss-1]]>d[lc];ss--)f[st[ss]]=st[ss-1];
		if(d[st[ss]]>d[lc])f[st[ss--]]=lc;
		if(st[ss]!=lc)st[++ss]=vi[++vs]=lc;
		st[++ss]=vi[++vs]=a[i];
	}
	for(;st[ss-1];ss--)f[st[ss]]=st[ss-1];
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a2.out","w",stdout);
	scanf("%d%d",&n,&m);sn=pow(n,0.5);
	fo(i,2,n)scanf("%d",&p[i]),ne[i]=la[p[i]],la[p[i]]=i;
	fo(i,1,n)scanf("%d",&b[i]);
	dfs(1);df2(1,1);aa[0].x=-1e9;
	fo(t,1,m){
		scanf("%d",&q[++qs]);
		if(qs==sn||t==m){
			build();cs=0;
			fo(i,2,vs){
				ss=0;js=vi[i];
				for(int x=js;x=p[x],x!=f[js];)if(!op[x])a[++ss]=b[x];
				sort(a+1,a+ss+1);gs=0;
				fo(j,1,ss){
					if(aa[gs].x!=a[j])aa[++gs]=no(a[j],0);
					aa[gs].y++;
				}
				be[js]=cs+1;en[js]=cs+gs+1;
				fo(j,0,gs){
					c[++cs]=aa[j];
					if(aa[j].x<0)w[js]=cs;
				}
			}
			fo(i,1,qs){
				js=q[i];
				if(js>0){
					if(b[js]<0)ans--;
					for(int j=js;j>1;){
						cnt[j]--;
						if(w[j]<en[j]&&c[w[j]+1].x+cnt[j]<0)ans+=c[++w[j]].y;
						j=f[j];
						if(!b[j]--&&!op[j])ans++;
					}
				}else{
					js=-js;
					if(b[js]<0)ans++;
					for(int j=js;j>1;){
						cnt[j]++;
						if(w[j]>=be[j]&&c[w[j]].x+cnt[j]>=0)ans-=c[w[j]--].y;
						j=f[j];
						if(!(++b[j])&&!op[j])ans--;
					}
				}
				op[js]^=1;printf("%d \n",ans);
			}
			fo(i,2,vs){
				js=vi[i];
				for(int x=js;x=p[x],x!=f[js];)b[x]+=cnt[js];
				cnt[js]=0;
			}qs=0;
		}
	}
}