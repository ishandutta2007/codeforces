#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[y]%mod)*inv[x-y]%mod;
}
int permute(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[x-y])%mod;
}
void precalc(){
	fact[0] = 1; inv[0] = 1;
	for(int i = 1; i<=2000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[2000000] = modpow(fact[2000000],mod-2);
	for(int i = 1999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n,x,pos;
	cin >> n >> x >> pos;
	int iter = 0;
	int leftcnt = 0; int rightcnt = 0;
	int left = 0; int right = n;
	while(left<right){
		int middle = (left+right)/2;
		if(middle<=pos){
			left = middle+1;
			if(middle<pos)leftcnt++;
		}
		else{
			rightcnt++;
			right = middle;
		}
	}
	int v = permute(x-1,leftcnt);
	int v2 = permute(n-x,rightcnt);
	//cout << v << " " << v2 << "\n";
	v*=v2; v%=mod;
	int rem = n-1-leftcnt-rightcnt;
	v*=fact[rem];
	v%=mod;
	cout << v << "\n";
	return 0;
}