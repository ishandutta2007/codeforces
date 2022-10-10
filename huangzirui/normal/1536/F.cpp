#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=1000010,mod=1e9+7;
int i,j,k,n,m,T;ll jc[maxn],ny[maxn],Pow[maxn];
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
ll C(int a,int b){
	if(b>a || b<0)return 0;
	return jc[a]*ny[b]%mod*ny[a-b]%mod;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	Pow[0]=1;for(i=1;i<maxn;i++)Pow[i]=Pow[i-1]*2%mod;
	jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
	ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
	cin>>n;
	ll ans=0;
	if(n&1){
		for(i=1;i<=n;i+=2){
			ans+=2*jc[n-i]*(C(n-i,i)+C(n-2-i+1,i-1))%mod;
			ans%=mod;
		}
	}else{
		ans=2*jc[n]%mod;
		for(i=2;i<=n;i+=2){
			ans+=2*jc[n-i]*(C(n-i,i)+C(n-2-i+1,i-1))%mod;
			ans%=mod;
		}
	}cout<<ans<<endl;
}