// Hydro submission #614c882b478454b8ebea50ac@1632406312843
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1010;
const int mod=1e9+7;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int t;
int dv[N],ans[N],mul[N];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int query(int n){
	if(n==0) return 0;
	if(n==1) return 2;
	int k=upper_bound(dv+1,dv+41,n)-dv-1;
	int res=n/dv[k];
	return (query(n%dv[k])+(res*ans[k])%mod)%mod;
}
signed main(){
	t=read();
	dv[1]=1;ans[1]=2;
	for(int i=2;i<=41;i++){
		dv[i]=dv[i-1]/gcd(dv[i-1],i)*i;
		mul[i]=i/gcd(dv[i-1],i);
		if(mul[i]>1) ans[i]=(ans[i-1]*mul[i]+1)%mod;
		else ans[i]=ans[i-1]+1;
	}
	while(t--) printf("%lld\n",query(read()));
	return 0;
}