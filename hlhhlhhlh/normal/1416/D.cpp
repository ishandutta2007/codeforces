// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=600010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m,q,num,mx,ha[maxn];
int fa[maxn][22],w[maxn];
vector <int> mp[maxn];
struct node{
	int x,y,tim;
}a[maxn];
struct que{
	int x,y;
}b[maxn];
bool cmp(node a,node b){ return (a.tim>b.tim); }
int faa[maxn],val[maxn];
int getfaa(int x){
	if (faa[x]==x) return x;
	faa[x]=getfaa(faa[x]); return faa[x];
}
int dfn[maxn],low[maxn],tt;
void dfs(int x,int faaa){
	fa[x][0]=faaa; for (int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	tt++; dfn[x]=tt;
	for (int i=0;i<mp[x].size();i++) dfs(mp[x][i],x);
	low[x]=tt;
}
struct SegmentTree{
	int inf,a[maxn]; 
	int l[maxn*4],r[maxn*4],mx[maxn*4],fla1[maxn*4];
	void updata(int x){
		mx[x]=max(mx[x*2],mx[x*2+1]);
	}
	void downflag(int x){
		if (l[x]==r[x]){
			fla1[x]=inf;
			return;
		}
		int ls=x*2,rs=x*2+1;
		if (fla1[x]!=inf){
			fla1[ls]=fla1[x]; 
			fla1[rs]=fla1[x]; 
			mx[ls]=fla1[x]; mx[rs]=fla1[x];
		}
		fla1[x]=inf;
	}
	void build(int x,int ll,int rr){
		int mid=(ll+rr)>>1;
		fla1[x]=inf;
		l[x]=ll; r[x]=rr;
		if (ll==rr){
			mx[x]=a[ll];
			return;
		}
		build(x*2,ll,mid);
		build(x*2+1,mid+1,rr);
		updata(x);
	}
	void changge(int x,int ll,int rr,int w){
		downflag(x);
		if ((ll<=l[x])&&(r[x]<=rr)){
			mx[x]=w;
			fla1[x]=w;
			return;
		}
		if ((r[x]<ll)||(rr<l[x])) return;
		changge(x*2,ll,rr,w); changge(x*2+1,ll,rr,w);
		updata(x);
	}
	int getmx(int x,int ll,int rr){
		downflag(x);
		if ((ll<=l[x])&&(r[x]<=rr)){ return mx[x]; }
		if ((r[x]<ll)||(rr<l[x])) return (-inf);
		return max(getmx(x*2,ll,rr),getmx(x*2+1,ll,rr));
	}
}segtre;
int getfa(int x,int tim){
	int i;
	for (i=20;i>=0;i--){
		if (val[fa[x][i]]>tim) x=fa[x][i];
	}
	return x;
}
int main(){
	
	n=read(); m=read(); q=read();
	for (i=1;i<=n;i++) w[i]=read();
	for (i=1;i<=n;i++) ha[w[i]]=i;
	for (i=1;i<=m;i++){
		a[i].x=read(); a[i].y=read(); a[i].tim=q+1;
	}
	for (i=1;i<=q;i++){
		b[i].x=read(); b[i].y=read();
		if (b[i].x==2) a[b[i].y].tim=i;
	}
	sort(a+1,a+m+1,cmp);
	for (i=1;i<=n*2;i++) faa[i]=i;
	for (i=1;i<=n;i++) val[i]=q+1;
	num=n;
	for (i=1;i<=m;i++){
		if (getfaa(a[i].x)!=getfaa(a[i].y)){
			num++; val[num]=a[i].tim;
			mp[num].push_back(getfaa(a[i].x));
			mp[num].push_back(getfaa(a[i].y));
			faa[getfaa(a[i].x)]=num;
			faa[getfaa(a[i].y)]=num;
		}
	}
	for (i=num;i>=1;i--) if (dfn[i]==0) dfs(i,0);
	for (i=1;i<=n;i++) segtre.a[dfn[i]]=w[i]; segtre.inf=1e9;
	segtre.build(1,1,num);
	for (i=1;i<=q;i++){
		if (b[i].x==1){
			tt=getfa(b[i].y,i);
			mx=segtre.getmx(1,dfn[tt],low[tt]);
			segtre.changge(1,dfn[ha[mx]],dfn[ha[mx]],0);
			printf("%d\n",mx);
		}
	}
	
	return 0;
}
/*

5 4 6
1 2 5 4 3
1 2
2 3
1 3
4 5
1 1
2 1
2 3
1 1
1 2
1 2

*/