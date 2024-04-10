#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll in[5],deg[5];
struct matrix{
	ll d[5][5];
	int wid,h;
	void reset(int a,int b){
		h=a;wid=b;
		for(register int i=0;i<a;++i)
			for(register int j=0;j<b;++j)
				d[i][j]=0;
	}
	matrix operator *(matrix b){
		matrix ans;
		ans.reset(h,b.wid);
		for(register int i=0;i<h;++i)
			for(register int j=0;j<wid;++j)
				for(register int k=0;k<b.wid;++k)
					ans.d[i][k]=(ans.d[i][k]+d[i][j]*b.d[j][k])%(mod-1);
		return ans;
	}
}c,cm,f[3],fm;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
ll fst(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1)
			ans=ans*x%mod;
		x=x*x%mod;
		k>>=1; 
	} 
	return ans;
}
void prepare(){
	c.reset(1,5);cm.reset(5,5);
	c.d[0][3]=2;c.d[0][4]=1;
	cm.d[0][1]=cm.d[1][2]=cm.d[3][3]=cm.d[4][4]=1;
	cm.d[4][3]=2;
	for(register int i=0;i<3;++i){
		f[i].reset(1,3);f[i].d[0][2-i]=1;
	}
	fm.reset(3,3);
	fm.d[0][0]=fm.d[1][0]=fm.d[2][0]=1;
	fm.d[0][1]=fm.d[1][2]=1;
}
int main(){
	prepare();
	for(register int i=0;i<5;++i)
		in[i]=read(),cm.d[i][0]=1;
	cm.d[4][0]=0;
	ll k=in[0]-3;
	while(k){
		if(k&1){
			for(register int i=0;i<3;++i)
				f[i]=f[i]*fm;
			c=c*cm;
		}
		fm=fm*fm;
		cm=cm*cm;
		k>>=1; 
	}
	deg[4]=c.d[0][0];
	for(register int i=0;i<3;++i)
		deg[1+i]=f[i].d[0][0];
	ll ans=1;
	for(register int i=1;i<5;++i)
		ans=ans*fst(in[i]%mod,deg[i])%mod;
	printf("%lld",ans);
	return 0;
}