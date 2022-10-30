// Hydro submission #631ed386bdf9bc31d15bff86@1662964614978
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define R register
using namespace std;
const long long mo=1e9+7;
const int N=2e5+5;
int m,n,cnt,u,v,sum,b[N],h[N],a[N],p[N],l[N],last[N<<1],prime[N],olx[N<<1],pos[N],map[N<<1],lg2[N<<1],ksm2[25],st[N<<2][25];
long long ans,dep[N],pre[N],inv[N],f[N],size[N],phi[N],mu[N];
bool bj[N];
void xxs()
{
	phi[1]=1;mu[1]=1;
	for (int i=2;i<=n;++i)
	{
		if (!phi[i])
		{
			prime[++cnt]=i;phi[i]=i-1;mu[i]=-1;
		}
		for (int j=1;j<=cnt&&i*prime[j]<=n;++j)
		{
			if (i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];mu[i*prime[j]]=0;break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];mu[i*prime[j]]=mu[i]*mu[prime[j]];
		}
	}
}
void ad(int u,int v)
{//cout<<u<<' '<<v<<endl;
	map[++sum]=v;last[sum]=l[u];l[u]=sum;
}
void dg(int x)
{
	olx[++cnt]=x;pos[x]=cnt;
	for (int i=l[x];i;i=last[i])
		if (!dep[map[i]])
		{
			dep[map[i]]=dep[x]+1;dg(map[i]);olx[++cnt]=x;
		}
	l[x]=0;
}
int lca(int u,int v)
{
	int l=pos[u],r=pos[v];
	if (l>r) swap(l,r);int len=lg2[r-l+1];
	return dep[st[l][len]]<dep[st[r-ksm2[len]+1][len]]?st[l][len]:st[r-ksm2[len]+1][len];
}
bool cmp(int s1,int s2){return pos[s1]<pos[s2];}
void dp(int x)
{
	if (bj[x]) size[x]=phi[a[x]];
	else size[x]=0;f[x]=0;
	for (int i=l[x];i;i=last[i])
	{
		dp(map[i]);
		f[x]=(f[x]+size[x]*size[map[i]]%mo*dep[x]%mo)%mo;size[x]=(size[x]+size[map[i]])%mo;
	}
	f[x]=f[x]*2ll%mo;
	for (int i=l[x];i;i=last[i]) f[x]=(f[x]+f[map[i]])%mo;
	if (bj[x]) f[x]=(f[x]+phi[a[x]]*phi[a[x]]%mo*dep[x]%mo)%mo;
	bj[x]=false;l[x]=0;
}
int main()
{
	lg2[1]=0;for (int i=2;i<=400000;++i) lg2[i]=lg2[i>>1]+1;
	ksm2[0]=1;for (int i=1;i<=20;++i) ksm2[i]=ksm2[i-1]<<1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),p[a[i]]=i;
	xxs();cnt=0;inv[1]=1;for (int i=2;i<=n;++i) inv[i]=inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);ad(u,v);ad(v,u);
	}
	dep[1]=1;dg(1);
	for (int i=1;i<=cnt;++i) st[i][0]=olx[i];
	for (int j=1;j<=lg2[cnt];++j)
		for (int i=1;i<=cnt;++i) st[i][j]=dep[st[i][j-1]]<dep[st[i+ksm2[j-1]][j-1]]?st[i][j-1]:st[i+ksm2[j-1]][j-1];
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;j+=i)
			pre[j]=(pre[j]+inv[phi[i]]*i%mo*mu[j/i]%mo)%mo;//,cout<<i<<' '<<j<<' '<<inv[phi[i]]*i%mo*mu[j/i]%mo<<' '<<mu[j/i]<<' '<<endl;
	for (int t=1;t<=n;++t)
	{
		m=sum=0;long long pre2=0,pre3=0;
		for (int i=1;i<=n/t;++i) h[++m]=p[i*t],bj[h[m]]=true,pre2=(pre2+phi[i*t])%mo;
		for (int i=1;i<=n/t;++i) pre3=(pre3+2ll*phi[i*t]*dep[p[i*t]]%mo*pre2%mo)%mo;
		sort(h+1,h+1+m,cmp);
		int tail=1;b[1]=1;//cout<<"!!!"<<' '<<ans<<' '<<pre[t]<<' '<<pre3<<endl;
		for (int i=1;i<=m;++i)
		{
			if (h[i]==1) continue;
			int jl=lca(b[tail],h[i]);
			while (dep[jl]<=dep[b[tail-1]]) ad(b[tail-1],b[tail]),tail--;
			if (dep[jl]<dep[b[tail]]) ad(jl,b[tail]),tail--;
			if (jl==b[tail]) b[++tail]=h[i];
			else b[++tail]=jl,b[++tail]=h[i];
		}
		while (tail>1) ad(b[tail-1],b[tail]),--tail;
		dp(1);//cout<<f[1]<<endl;
		ans=((ans+pre[t]*(pre3-2ll*f[1]%mo+mo)%mo)%mo+mo)%mo;
	}
	printf("%lld",ans*inv[n]%mo*inv[n-1]%mo);
	return 0;
}