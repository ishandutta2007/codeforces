#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define pb push_back
#define cnt(x) __builtin_popcount(x)
using namespace std;
const int N=1e5+5,M=512,mo=998244353;
int n,m,ds,x,y,iv,ans;
int d[N],deg[N],sg[N],sum[M];
int f[M];
vector<int>e[N],re[N];
bool bz[N];
int pw(int x,int y=mo-2){
	x%=mo;
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
void up(int &x){x+=x>>31&mo;}
void fwt(int *a,int sgn){
	int A;
	for(int i=1;i<M;i<<=1)for(int j=0;j<M;j+=i*2)
		ff(k,0,i)A=a[i+j+k],up(a[i+j+k]=a[j+k]-A),up(a[j+k]+=A-mo);
	if(sgn){
		int y=pw(M);
		ff(i,0,M)a[i]=(ll)a[i]*y%mo;
	}
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,m)scanf("%d%d",&x,&y),e[y].pb(x),re[x].pb(y),deg[x]++;
	fo(i,1,n)if(!deg[i])d[++ds]=i;
	for(int l=0,x;++l<=ds;){
		x=d[l];
		for(int i:re[x])bz[sg[i]]=1;
		for(;bz[sg[x]];)++sg[x];
		for(int i:re[x])bz[sg[i]]=0;
		
		for(int i:e[x])if(!--deg[i])d[++ds]=i;
	}
	fo(i,1,n)sum[sg[i]]++;
	iv=pw(n+1);
	ff(i,0,M){
		sum[i]=(ll)sum[i]*iv%mo;
		f[i]=sum[i];
	}
	fwt(f,0);
	ff(i,0,M)f[i]=pw(mo+1-f[i]);
	fwt(f,1);
	printf("%d\n",(mo+1-(ll)f[0]*iv%mo)%mo);
}