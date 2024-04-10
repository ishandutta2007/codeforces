#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
int n,mul[110000],add[110000];
string s,t[110000];
int main(){
	cin>>s; cin>>n;
	for (int i=0;i<=n-1;i++) cin>>t[i];
	for (int i=0;i<=9;i++) mul[i]=10,add[i]=i;
	for (int i=n-1;i>=0;i--){
		int now=t[i][0]-'0';
		ll Mul=1,Add=0;
		for (int j=3;j<t[i].size();j++){
			int c=t[i][j]-'0';
			Mul=Mul*mul[c]%Mod;
			Add=(Add*mul[c]+add[c])%Mod;
		}
		mul[now]=Mul; add[now]=Add;
	}
	ll ans=0;
	for (int i=0;i<s.length();i++){
		int c=s[i]-'0';
		ans=(ans*mul[c]+add[c])%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}