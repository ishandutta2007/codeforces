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
	if(y<0||x<0)return 0;
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
	int t;
	cin >> t;
	while(t--){
		int n,l,r;
		cin >> n >> l >> r;
		if(abs(l-1)<r-n){
			int temp = 1-(r-n);
			r = n+abs(l-1);
			l = temp;
		}
		//cout << l << " " << r << " " << "\n";
		int x = 1;
		if(r-n>0){
			x = r-n;
		}
		if(abs(l-1)>0){
			x = min(x,abs(l-1));
		}
		int ans = (x-1)*choose(n,n/2)%mod;
		if(n%2==1)ans+=(x-1)*choose(n,n/2+1)%mod;
		ans%=mod;
		int left = 0; int right = n+1;//left and right mean that the first (left value) amount of values in the array are too small or too big to subtract or add x
		//cout << ans << " " << x << "\n";
		while(left<=n&&right>=1){
			while(left-x<l-1){
				left++;	
			}
			while(right+x>r+1){
				right--;
			}
			//cerr << left << " " << right << " " << x << "\n";
			int rem = right-left-1;
			ans+=choose(rem,n/2-left);
			ans%=mod;
			if(n%2==1)ans+=choose(rem,n/2+1-left);
			ans%=mod;
			x++;
		}
		cout << ans << "\n";
	}
	return 0;
}