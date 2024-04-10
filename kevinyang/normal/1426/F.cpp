#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0; int c = 0; int d = 0;
	int a2 = 0; int c2 = 0; int d2 = 0;
	a2 = count(s.begin()+1,s.end(),'a');
	c2 = count(s.begin()+1,s.end(),'c');
	d2 = count(s.begin()+1,s.end(),'?');
	if(s[0]=='a')a++;
	if(s[0]=='c')c++;
	if(s[0]=='?')d++;
	int ans = 0;
	for(int i = 1; i<s.length(); i++){
		if(s[i]=='a')a2--;
		if(s[i]=='c')c2--;
		if(s[i]=='?')d2--;
		if(s[i]=='b'||s[i]=='?'){
			ans+=modpow(3,d)*modpow(3,d2)%mod*a%mod*c2%mod; ans%=mod;
			if(d>0)ans+=modpow(3,d-1)*d%mod*modpow(3,d2)%mod*c2%mod; ans%=mod;
			if(d2>0)ans+=modpow(3,d)*modpow(3,d2-1)%mod*d2%mod*a%mod; ans%=mod;
			if(d>0&&d2>0)ans+=modpow(3,d-1)*d%mod*modpow(3,d2-1)%mod*d2%mod; ans%=mod;
		}
		if(s[i]=='a')a++;
		if(s[i]=='c')c++;
		if(s[i]=='?')d++;
	}
	cout << ans << "\n";
	return 0;
}