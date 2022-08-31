#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
vector<int> factorize(int n){
	vector<int> vec;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			vec.push_back(i);
		}
	}
	if(n != 1) vec.push_back(n);
	return vec;
}
int main(){
	int x, y;
	cin >> x >> y;
	if(y % x != 0){
		cout << 0;
		return 0;
	}
	y /= x;
	vector<int> vec = factorize(y);
	int n = vec.size();
	long long ans = 0;
	for(int i = 0; i < (1 << n); i++){
		int cnt = 0;
		int d = 1;
		for(int j = 0; j < n; j++)
			if(i >> j & 1){
				d *= vec[j];
				cnt++;
			}
		int res = powr(2, y / d - 1);
		if(cnt & 1) ans -= res;
		else ans += res;
	}
	cout << (ans % mod + mod) % mod << endl;
	return 0;
}