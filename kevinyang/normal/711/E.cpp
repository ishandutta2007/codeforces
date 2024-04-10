#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e6+3;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int cnt2(int x){
	int ans = 0;
	for(int cur = 2; cur<=(int)1e18; cur*=2){
		ans+=x/cur;
	}
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	if(true){
		int cur = 1;
		for(int i = 0; i<n; i++){
			cur*=2;
			if(cur>k)break;
		}
		if(cur<k){
			cout << "1 1\n";
			return 0;
		}
	}
	int reduce = cnt2(k-1);
	int modinv = modpow(2,mod-2);
	int start = modpow(2,n);
	int den = modpow(start,k-1);
	den*=modpow(modinv,reduce); den%=mod;
	int num = 1;
	for(int i = 1; i<=k-1; i++){
		int v = start-i+mod;
		v%=mod;
		num*=v;
		num%=mod;
		if(num==0)break;
	}
	if(num==0)cout << den << " ";
	else{
		num*=modpow(modinv,reduce); num%=mod;
		num = den-num;
		num+=mod; num%=mod;
		cout << num << " ";
	}
	cout << den << "\n";
	return 0;
}