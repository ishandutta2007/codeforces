#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1.4e5,mo=998244353;
int n,M,K,t,sns[N];
int w[N*2],ne[N*2],la[N],size[N],fa[N],r[N];
ll f[N],g[N],ccnt;
int jc[N],ny[N];
void read(int &n){
	char c;for(;(c=getchar())<'0'||c>'9';);
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int dec(int x){return x>=mo?x-mo:x;}
ll mul(ll a,ll b,ll mo){
	if (mo<=1000000000)return a*b%mo;
	ll c=(ld)a*b/mo,z=a*b-c*mo;
	if (z<0)z+=mo;if (z>=mo)z-=mo;
	return z;
}
ll power(ll a,ll b,ll mo){
	ll ans=1;
	while (b){
		if (b&1)ans=mul(ans,a,mo);
		a=mul(a,a,mo);
		b>>=1;
	}return ans;
}
struct mod{
	ll mo,w[N];
	void pre(ll x){
		mo=x;
		w[0]=1,w[1]=power(3,(mo-1)/M,mo);
		for (int i=2;i<=M;i++)w[i]=mul(w[i-1],w[1],mo);
	}
}m1,m2,m3;
void link(int x,int y){w[++t]=y,ne[t]=la[x],la[x]=t;}
void dfs(int x){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		sns[x]++;
		fa[z]=x;
		dfs(z);
		size[x]+=size[z]; 
	}size[x]++;
}
void dft(ll *a,int sig,int Mx,mod &x){
	for (int i=1;i<Mx;i++){
		r[i]=(r[i>>1]>>1)+(i&1)*(Mx>>1);
		if (r[i]<i)swap(a[i],a[r[i]]);
	}
	for (int m=2;m<=Mx;m<<=1){
		int n=m/2,ax=M/m;
		for (int i=0;i<n;i++){
			ll wn=x.w[(i*ax*sig+M)%M];
			for (int j=i;j<Mx;j+=m){
				int k=j+n;ll u=a[j],v=mul(a[k],wn,x.mo);
				a[j]=u+v;
				a[k]=u-v+x.mo;
				if (a[j]>x.mo)a[j]-=x.mo;
				while (a[k]>x.mo)a[k]-=x.mo;
				ccnt++;
			}
		}
	}
}
ll p[N*2],mx,cd;
int st[N];
ll c1[N],c2[N],c3[N],a[N],b[N];
void mul(ll *a,ll *b,ll *c,mod &x,int Mx){
	dft(a,1,Mx,x);dft(b,1,Mx,x);
	for (int i=0;i<Mx;i++)c[i]=mul(a[i],b[i],x.mo);
	dft(c,-1,Mx,x);
	ll ny=power(Mx,x.mo-2,x.mo);
	for (int i=0;i<Mx;i++)c[i]=mul(c[i],ny,x.mo);
}
ll Ans;
int mrk[N],sum[N];
ll A(int n,int m){
	if (n<m)return 0;
	return (ll)jc[n]*ny[n-m]%mo;
}
void dp(int x){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		dp(z);
		(Ans+=(ll)sum[z]*sum[x])%=mo;
		sum[x]=dec(sum[x]+sum[z]);
	}
	sum[x]=dec(sum[x]+f[x]);
	(Ans+=sum[x]*g[x])%=mo;
}
ll merge(ll a1,ll p1,int a2,int p2){
	ll p_=power(p1%p2,p2-2,p2),k1=(a2-a1%p2+p2)*p_%p2;
	if (p1<mo&&p2<mo)return a1+p1*k1;
	return (a1+p1%mo*k1)%mo;
}
int main(){
	cin>>n>>K;
	if(K==1){
		printf("%I64d",((ll)n*(n-1)>>1)%mo);
		return 0;
	}
	for (M=1;M<=n;M<<=1);
	for (int i=1;i<M;i++)r[i]=(r[i>>1]>>1)+(M>>1)*(i&1);
	m1.pre(1+(29LL<<57LL));
	m2.pre(998244353);
	jc[0]=ny[0]=1;
	for (int i=1;i<=M;i++)jc[i]=(ll)jc[i-1]*i%mo;
	ny[M]=power(jc[M],mo-2,mo);
	for (int i=M;i;i--)ny[i-1]=(ll)ny[i]*i%mo;
	for (int i=1;i<n;i++){
		int x,y;
		read(x),read(y);
		link(x,y);
		link(y,x);
	}
	dfs(1);
	for (int x=1;x<=n;x++){
		t=0;p[0]=1;
		if (sns[x]<=200){
			int mx=0;
			for (int y=la[x];y;y=ne[y]){
				int z=w[y];
				if (z==fa[x])continue;
				for (int i=++mx;i>=1;i--)
					p[i]=(p[i]+p[i-1]*size[z])%mo;
			}
		}
		else {cd=0;
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (z==fa[x])continue;
			if (size[z]==1){cd++;continue;}
			st[++t]=t*2-2;
			p[t*2-2]=1,p[t*2-1]=size[z];
		}
		st[t+1]=t*2;
		if (cd){
			int qn=st[++t]=t*2-2;
			for (int i=0;i<=cd;i++)p[qn++]=(ll)jc[cd]*ny[i]%mo*ny[cd-i]%mo;
			st[t+1]=qn;
		}
		for (int step=1;step<t;step<<=1){
			for (int i=1;i+step<=t;i+=step*2){
				int n=st[i+step]-st[i],m=st[min(i+2*step,t+1)]-st[i+step],Mx;
					for (int u=0;u<n;u++){
						a[u]=p[u+st[i]];
						if (a[u]==0){
							n=u+1;
							break;
						}
					}
					for (int u=0;u<m;u++){
						b[u]=p[u+st[i+step]];
						if(b[u]==0){
							m=u+1;
							break;
						}
					}
				if (n+m<=8192){
					for (int u=0;u<n;u++)p[u+st[i]]=0;
					for (int u=0;u<m;u++)p[u+st[i+step]]=0;
					for (int u=0;u<n;u++)
					for (int v=0;v<m;v++)
						(p[st[i]+u+v]+=a[u]*b[v])%=mo;
					for (int u=0;u<n||u<m;u++)a[u]=b[u]=0;
				}
				else{
					for (Mx=1;Mx<n+m-1;Mx<<=1);
					mul(a,b,c1,m1,Mx);
					for (int u=0;u<Mx;u++)a[u]=b[u]=0;
					for (int u=0;u<n;u++)a[u]=p[u+st[i]];
					for (int u=0;u<m;u++)b[u]=p[u+st[i+step]];
					mul(a,b,c2,m2,Mx);
					for (int u=0;u<Mx;u++)a[u]=b[u]=0;
					for (int u=0;u<n+m;u++)
					p[st[i]+u]=merge(c1[u],m1.mo,c2[u],m2.mo);
				}
			}
		}}
		for (int i=0;i<=min(K,sns[x]);i++)(f[x]+=p[i]*A(K,i))%=mo;
		for (int y=la[x];y;y=ne[y]){
			int z=w[y],d=size[z];
			if (z==fa[x])continue;
			if (mrk[d]){g[z]=mrk[d];continue;}g[z]=1;
			for (int i=sns[x]+1;i>=1;i--)p[i]=(p[i]+p[i-1]*(size[1]-size[x]))%mo;
			for (int i=1;i<=sns[x]+1;i++)p[i]=(p[i]-p[i-1]*size[z]+mo)%mo,g[z]=(g[z]+p[i]*A(K,i))%mo;
			for (int i=sns[x]+1;i>=1;i--)p[i]=(p[i]+p[i-1]*size[z])%mo;
			for (int i=1;i<=sns[x]+1;i++)p[i]=(p[i]-p[i-1]*(size[1]-size[x])+mo)%mo;
			mrk[d]=g[z];
		}
		for (int y=la[x];y;y=ne[y])mrk[size[w[y]]]=0;
		for (int i=0;i<=sns[x];i++)p[i]=0;
	}
	dp(1);
	cout<<Ans<<endl;
}