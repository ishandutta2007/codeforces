#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e9+7;
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fac[N],ifac[N];
inline int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
inline void init(){
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%p;
	ifac[N-1]=inv(fac[N-1]);
	for(int i=N-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%p;
	return; 
}
inline int C(int n,int m){
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main(){
	int t=read();
	init();
	while(t--){
		int n=read(),k=read();
		if(n%2==0){
			int sum0=0,sum=inv(2,n);
			for(int i=0;i<n;i+=2)
				sum0=(sum0+C(n,i))%p;
			int ans=0;
			for(int i=1;i<=k;i++)
				ans=(ans+inv(sum0,i-1)*inv(sum,k-i)%p)%p;
			ans=(ans+inv(sum0,k))%p;
			cout<<ans<<endl;
			continue;
		}
		int res=0;
		for(int i=0;i<n;i+=2)res=(res+C(n,i))%p;
		res=(res+1)%p;
		cout<<inv(res,k)<<endl;
	}
	return 0;
}