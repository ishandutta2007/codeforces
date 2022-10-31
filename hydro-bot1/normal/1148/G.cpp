// Hydro submission #62c56333c3a9fda562296aea@1657103156439
#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp void write(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int n,k,c[N+5],d[N+5][10],p[N+5],q[N+5];vector<int> v[N+5];
bool cmp(int x,int y) {return v[x].size()>v[y].size();}
namespace S
{
	#define V 10000000
	int f[V+5];
	void A(int o,int v=1,int x=1,int t=1)
	{
		if(x>c[o]) return (void)(f[t]+=v);A(o,v,x+1,t),A(o,-v,x+1,t*d[o][x]);
	}
	int Q(int o,int x=1,int t=1)
	{
		if(x>c[o]) return f[t];return Q(o,x+1,t)+Q(o,x+1,t*d[o][x]);
	}
}
int ql[N+5],qr[N+5];void Solve(int l,int r,int L,int R)
{
	int i;if(l==r||L>R) {for(i=L;i<=R;++i) v[p[l]].push_back(q[i]);return;}
	int u=l+r>>1,tl=0,tr=0;for(i=l;i<=u;++i) S::A(p[i]);
	for(i=L;i<=R;++i) (S::Q(q[i])?ql[++tl]:qr[++tr])=q[i];
	for(i=1;i<=tl;++i) q[L+i-1]=ql[i];for(i=1;i<=tr;++i) q[L+tl+i-1]=qr[i];
	Solve(u+1,r,L+tl,R);for(i=l;i<=u;++i) S::A(p[i],-1);Solve(l,u,L,L+tl-1);
}
int main()
{
	int i,j,x;for(read(n,k),i=1;i<=n;++i)
		{for(read(x),j=2;j*j<=x;++j) if(!(x%j)) {d[i][++c[i]]=j;while(!(x%j)) x/=j;}x^1&&(d[i][++c[i]]=x);}
	int t1=0,t2=0;for(i=1;i<=n;++i) S::Q(i)?q[++t2]=i:(S::A(i),p[++t1]=i);
	if(t1>=k) {for(i=1;i<=k;++i) write(p[i]);return 0;}
	for(i=1;i<=t1;++i) S::A(p[i],-1);Solve(1,t1,1,t2),sort(p+1,p+t1+1,cmp);
	for(i=1;i<=t1;++i)
	{
		if(k==1) {v[p[1]].pop_back(),v[p[i]].resize(1),t1=i;break;}
		if(k<=v[p[i]].size()+1) {v[p[i]].resize(k-1),t1=i;break;}k-=v[p[i]].size()+1;
	}
	for(i=1;i<=t1;++i) for(write(p[i]),x=v[p[i]].size(),j=0;j^x;++j) write(v[p[i]][j]);return 0;
}