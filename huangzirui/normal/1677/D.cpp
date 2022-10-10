#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1000010,mod=998244353;
int i,j,k,n,m,T,a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)a[i]=read();
		ll ans=1;
		for(i=1;i<=m;i++)if(a[n-i+1]>0)ans=0;
		for(i=1;i<=n;i++){
			if(i<=m)ans*=i;
			else{
				if(!a[i-m])ans*=m+1;
				if(a[i-m]<0)ans*=m+1+(i-m-1);
			}
			ans%=mod;
//			cerr<<i<<' '<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}