#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline ll read(){
	char c;ll x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int mod=1e9+7;
int i,j,k,n,m;
ll S=1;bool is=0;
ll ksm(ll sum,ll num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
int main() {
	cin>>n;
	S=2;
	for(i=1;i<=n;i++){
		ll a=read();
		is+=(a&1)==0;
		S=ksm(S,a);
	}
	if(is)printf("%lld/%lld\n",(S+2)*ksm(6,mod-2)%mod,S*ksm(2,mod-2)%mod);
	else printf("%lld/%lld\n",(S-2+mod)%mod*ksm(6,mod-2)%mod,S*ksm(2,mod-2)%mod);
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}