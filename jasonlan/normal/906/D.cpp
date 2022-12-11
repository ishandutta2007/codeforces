#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=101000;
int n,m,q;
int que[maxn],cnt;
int num[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))
		res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int phi(int p){
	int ans=p;
	for(register int i=2;i*i<=p;++i){
		if(!(p%i)){
			ans=ans/i*(i-1);
			while(!(p%i))p/=i;
		}
	}
	if(p>1)ans=ans/p*(p-1);
	return ans;
}
ll mod(ll x,ll p){
	return x<p?x:(x%p+p);
}
int qpow(int x,int p,int k){
	int res=1;
	while(k){
		if(k&1)res=mod((ll)res*x,p);
		x=mod((ll)x*x,p);
		k>>=1;
	}
	return res;
}
ll query(int l,int r,int st){
	if(!que[st])return 1;
	if(l==r)return mod(num[l],que[st]);
	ll rans=query(l+1,r,st+1);
	return qpow(num[l],que[st],rans);
}
int main()
{
	n=read();m=read();
	que[0]=m;
	while(que[cnt]!=1)
		que[cnt+1]=phi(que[cnt]),++cnt;
	for(register int i=1;i<=n;++i)
		num[i]=read();
	q=read();
	for(register int i=0,l,r;i<q;++i){
		l=read();r=read();
		printf("%lld\n",query(l,r,0)%m);
	}
	return 0;
}