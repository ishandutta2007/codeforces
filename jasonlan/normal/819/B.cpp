#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1010000,k=50;
int n;
int p[maxn];
ll add[maxn],add2[maxn],ans[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)
		p[i]=read();
	//i 
	for(register int i=1,delta;i<=n;++i)
		if(i<=p[i]){
			delta=p[i]-i;
			if(delta>0)
				++add[delta-1];
			//n1 n-i+1.
			++add[n-1];
			--add[n-i];
			add2[n-1]+=p[i]-i;
			add2[n-i]-=p[i]-1;
		}
		else{
			++add[n-i+p[i]-1];
			--add[n-i];
			add2[n-i]-=p[i]-1;
		}
	for(register int i=n-1;~i;--i){
		add[i]+=add[i+1];
		add2[i]+=add[i];
	}
	for(register int i=n-1;~i;--i){
		add2[i]+=add2[i+1];
		ans[i]+=add2[i];
	}
	for(register int i=0;i<=n;++i)
		add[i]=add2[i]=0;
	//i 
	for(register int i=1,delta;i<=n;++i)
		if(i<=p[i]){
			++add[p[i]-i+1];
			--add[n-i+1];
			add2[n-i+1]-=n-p[i];
			//n1 n-i+1.
		}
		else{
			++add[n-i+p[i]+1];
			++add[0];
			--add[n-i+1];
			add2[0]+=i-p[i]-1;
			add2[n-i+1]-=n-p[i];
		}
	for(register int i=1;i<n;++i)
		add[i]+=add[i-1];
	for(register int i=0;i<n;++i){
		add2[i]+=add[i];
		if(i>0)add2[i]+=add2[i-1];
		ans[i]+=add2[i];
	}
	ll pans=1ll*n*n;
	int sk=0;
	for(register int i=0;i<n;++i)
		if(ans[i]<pans){
			pans=ans[i];sk=i;
		}
	printf("%lld %d",pans,sk);
	return 0;
}