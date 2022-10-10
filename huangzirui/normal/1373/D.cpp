#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,a[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		n=read();
		ll ans=0,Sum=0,Max=0;
		for(i=1;i<=n;i++){
			a[i]=read();
			if(i%2==1)ans+=a[i],a[i]*=-1;
		}
		for(i=1;i<=n-1;i+=2){
			Sum+=a[i]+a[i+1];
			Max=max(Max,Sum);
			if(Sum<0)Sum=0;
		}
		Sum=0;
		for(i=2;i<=n-1;i+=2){
			Sum+=a[i]+a[i+1];
			Max=max(Max,Sum);
			if(Sum<0)Sum=0;
		}
		printf("%lld\n",ans+Max);
	}
	return 0;
}