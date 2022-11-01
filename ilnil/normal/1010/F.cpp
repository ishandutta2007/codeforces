#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define dot(a,b)ff(i,0,Q)a[i]=(ll)a[i]*b[i]%mo
#define ll long long
#define poly vector<int>
#define rs resize
#define pb push_back
using namespace std;
const int N=1e5+5,M=(1<<17)+5,mo=998244353;
int n,x,y,ans;
ll s;
int hv[N],fa[N],si[N],d[N],su[N],ds;
vector<int>e[N];
poly a[N],b[N];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
namespace NTT{
	int w[M],h[M],Q;
	void print(poly &a){
		ff(i,0,a.size())printf("%d ",(a[i]+mo)%mo);
		printf("\n");
	}
	void init(int n){
		for(Q=1;Q<=n;Q<<=1);
		for(int i=1;i<Q;i<<=1){
			int g=ksm(3,(mo-1)/(i+i));w[i]=1;
			ff(j,1,i)w[i+j]=(ll)w[i+j-1]*g%mo;
		}
	}
	void pre(int n){
		for(Q=1;Q<=n;Q<<=1);
		ff(i,1,Q)h[i]=(h[i>>1]>>1)|(i&1?Q>>1:0);
	}
	void dft(poly &a,int sgn){
		a.rs(Q);
		ff(i,1,Q)if(h[i]>i)swap(a[i],a[h[i]]);ll A;
		for(int i=1;i<Q;i<<=1)for(int j=0;j<Q;j+=i*2)
			ff(k,0,i)A=(ll)w[i+k]*a[i+j+k],a[i+j+k]=(-A+a[j+k])%mo,a[j+k]=(A+a[j+k])%mo;
		if(sgn){
			reverse(a.begin()+1,a.end());
			int y=ksm(Q,mo-2);
			ff(i,0,Q)a[i]=(ll)a[i]*y%mo;
		}
	}
	poly operator*(const poly &a,const poly &b){
		static poly ntta,nttb;
		ntta=a;nttb=b;
		int n=(int)ntta.size()+nttb.size()-2;
		pre(n);
		dft(ntta,0);dft(nttb,0);
		dot(ntta,nttb);
		dft(ntta,1);
		ntta.rs(n+1);
		return ntta;
	}
	poly operator+(const poly &a,const poly &b){
		static poly c;
		c=a;
		c.rs(max(a.size(),b.size()));
		ff(i,0,b.size())c[i]=(c[i]+b[i])%mo;
		return c;
	}
}
using namespace NTT;
void dfs(int x){
	si[x]=1;
	for(int i:e[x])if(i!=fa[x]){
		fa[i]=x;
		dfs(i);
		si[x]+=si[i];
		if(si[i]>si[hv[x]])hv[x]=i;
	}
}
int find(int l,int r){
	int ans=l,len=su[r]+su[l-1]>>1;
	for(int L=l,R=r,mid;mid=L+R>>1,L<=R;)
		if(su[mid]<=len)ans=mid,L=mid+1;else R=mid-1;
	if(su[r]-su[ans+1]>su[ans]-su[l-1])++ans;
	return ans;
}
void divide(int l,int r){
	if(l==r)return;
	int m=find(l,r);
	divide(l,m);divide(m+1,r);
	a[d[l]]=a[d[l]]*a[d[m+1]];
	a[d[m+1]].clear();
}
void divide2(int l,int r){
	if(l==r)return;
	int m=find(l,r);
	divide2(l,m);divide2(m+1,r);
	b[d[l]]=b[d[l]]+a[d[l]]*b[d[m+1]];
	a[d[l]]=a[d[l]]*a[d[m+1]];
	a[d[m+1]].clear();
	b[d[m+1]].clear();
}
void dfs2(int x,int st){
	if(!hv[x]){
		d[ds=1]=x;
		a[x].rs(1);
		b[x].rs(2);
		a[x][0]=0;
		b[x][0]=b[x][1]=1;
		for(int y=x;y!=st;){
			y=fa[y];
			d[++ds]=y;
			b[y].rs(1);b[y][0]=1;
		}
		reverse(d+1,d+ds+1);
		d[ds+1]=0;
		fo(i,1,ds)su[i]=si[st]-si[d[i+1]];
		divide2(1,ds);
		a[st]=b[st];
		return;
	}
	for(int i:e[x])if(i!=fa[x]&&i!=hv[x])dfs2(i,i);
	a[x].rs(2);a[x][1]=1;
	d[ds=1]=x;su[1]=1;
	for(int i:e[x])if(i!=fa[x]&&i!=hv[x])d[++ds]=i,su[ds]=su[ds-1]+si[i];
	divide(1,ds);
	dfs2(hv[x],st);
}
int main(){
	scanf("%d%lld",&n,&s);s%=mo;
	fo(i,2,n)scanf("%d%d",&x,&y),e[x].pb(y),e[y].pb(x);
	init(n);
	dfs(1);
	dfs2(1,1);
	int c=1;
	fo(i,1,n){
		ans=((ll)c*a[1][i]+ans)%mo;
		c=(ll)c*(s+i)%mo*ksm(i,mo-2)%mo;
	}
	printf("%d\n",(ans+mo)%mo);
}