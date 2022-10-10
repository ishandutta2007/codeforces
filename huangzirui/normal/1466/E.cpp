#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=500010,mod=1e9+7;
int i,j,k,n,m,T,num[65][2];ll a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		memset(num,0,sizeof(num));
		for(i=1;i<=n;i++){
			a[i]=read();
			for(j=0;j<=61;j++){
				if(a[i] & (1ll<<j))num[j][1]++;
				else num[j][0]++;
			}
		}ll ans=0;
		for(i=1;i<=n;i++){
			ll S1=0,S2=0;
			for(j=0;j<=61;j++){
				if(a[i]&(1ll<<j))S1+=num[j][1]*((1ll<<j)%mod)%mod;
				if(a[i]&(1ll<<j))S2+=n*((1ll<<j)%mod)%mod;
				else S2+=num[j][1]*((1ll<<j)%mod)%mod;
				S1%=mod;S2%=mod;
			}ans+=S1*S2%mod;ans%=mod;
		}cout<<ans<<endl;
	}
	return 0;
}