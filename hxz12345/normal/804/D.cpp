#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
map<pair<int,int>,double> HH;
int rt,mx,vv,down[1001010],siz,type,r1,r2,now,tot,idk[1001010],f[1001010],a[1001010],b[1001010],d[1001010],dep[1001010],cnt;
long long ux,i,j,n,m,Q,x,y,xx,yy,uu,ans;
long long val[1001010];
vector<long long> E[1001010];
vector<long long> F[1001010];
vector<long long> V[1001010];
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p) if (y&1) ans=ans*x % p;return ans;
}
int find(int x){
	if (f[x]==x) return f[x];f[x]=find(f[x]);return f[x];
}
void add(int x,int y){
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa){
	for (int i=d[x];i;i=b[i])
	    if (a[i]!=fa){
	    	dep[a[i]]=dep[x]+1;
	    	sc(a[i],x);
		}
}
void Main(){
	x=read();y=read();
	if (find(x)==find(y)){puts("-1");return ;}
	xx=find(x);yy=find(y);
	if (V[xx].size()>V[yy].size()) swap(xx,yy);
	if (HH[make_pair(xx,yy)]!=0){printf("%.8lf\n",HH[make_pair(xx,yy)]);return ;}
	ux=max(val[x],val[y]);
	//dep[i]+dep[j]+1<=ux
	//dep[j]<=ux-dep[i]-1
	ans=0;
	for (i=0;i<V[xx].size();i++){
		     j=lower_bound(F[yy].begin(),F[yy].end(),ux-down[V[xx][i]]-1)-F[yy].begin();
		     ans=ans+j*ux+(E[yy][j]+(down[V[xx][i]]+1)*(V[yy].size()-j)); 
		     }
	long long vah=V[xx].size()*V[yy].size();
	HH[make_pair(xx,yy)]=(double)ans/vah;
	printf("%.8lf\n",(double)ans/vah);
	return ;
}
int main(){
	n=read();m=read();Q=read();
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=m;i++){
		x=read();y=read();add(x,y);add(y,x);
		r1=find(x);r2=find(y);f[r1]=r2;
	}
	for (i=1;i<=n;i++) V[find(i)].push_back(i);
	for (now=1;now<=n;now++)
	     if (find(now)==now){
	     	tot=0;
	     	for (i=0;i<V[now].size();i++) idk[++tot]=V[now][i];
			rt=V[now][0];
			for (i=1;i<=tot;i++) dep[idk[i]]=0;sc(rt,0);
			 mx=0;
	     	for (i=1;i<=tot;i++)
	     	    if (dep[idk[i]]>mx) mx=dep[idk[i]],rt=idk[i];
			for (i=1;i<=tot;i++) dep[idk[i]]=0;sc(rt,0);vv=0;
	     	for (i=1;i<=tot;i++) down[idk[i]]=dep[idk[i]],vv=max(vv,dep[idk[i]]);
	     	for (i=1;i<=tot;i++) val[idk[i]]=vv;
	     	mx=0;
	     	for (i=1;i<=tot;i++)
	     	    if (dep[idk[i]]==vv) rt=idk[i];
	     	for (i=1;i<=tot;i++) dep[idk[i]]=0;sc(rt,0);
	     	for (i=1;i<=tot;i++) down[idk[i]]=max(down[idk[i]],dep[idk[i]]);
	     	for (i=1;i<=tot;i++) F[now].push_back(down[idk[i]]);
	     	sort(F[now].begin(),F[now].end());siz=F[now].size();
	     	E[now].resize(siz+3);
	     	E[now][siz]=0;
	     	for (i=siz-1;i>=0;i--) E[now][i]=(E[now][i+1]+F[now][i]);
		 }
	for (;Q;Q--) Main();
	return 0;
}
/*
dep[i] i
val[i] i
max(val[i],val[j])=Q
sum(max(Q,dep[i]+dep[j]+1))
<=\sqrt(n) 
idep[j]<=Q-dep[i]-1

  
 j 
 
O(nsqrt(n)log)O(nsqrt(n))? 
*/