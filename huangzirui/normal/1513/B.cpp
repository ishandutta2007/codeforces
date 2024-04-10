#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010,mod=1000000007;
int i,j,k,n,m,T;
ll a[maxn],jc[maxn];
int main(){
	jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=32;i++){
			bool b=true;
			for(j=1;j<=n;j++)if(((1ll<<i-1)&a[j])==0)b=false;
			if(b)for(j=1;j<=n;j++)a[j]-=(1ll<<i-1);
		}sort(a+1,a+1+n);int s=0;
		for(i=1;i<=n;i++)if(a[i]==0)s++;
		printf("%lld\n",1ll*s*(s-1)%mod*jc[n-2]%mod);
	}
	return 0;
}