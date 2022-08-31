#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int base = 541;
const int g = 5;

inline int powr(int a, int b){
	int x = 1;
	for(; b; b >>= 1, a = (a * 1ll * a) % mod)
		if(b & 1)
			x = (x * 1ll * a) % mod;
	return x;
}

inline int getHash(string s){
	int ret = 0;
	for(int i = 0; i < s.length(); i++){
		ret = (ret * 1ll * base + s[i] - 'a' + 1) % mod;
	}
	return ret;
}

int getHash(int a, int b){
	return (powr(g, a) + powr(g, b)) % mod;
}
inline int gh(const string & s){
	int n = s.length();
	if(n & 1){
		return getHash(s);
	}
	string s1 = s.substr(0, n >> 1);
	string s2 = s.substr(n >> 1, n >> 1);
	int ret = getHash(gh(s1), gh(s2));;
	return ret;
}

int main(){
	string a, b;
	cin.tie(0);
	cin >> a >> b;
	cout << ((gh(a) == gh(b)) ? "YES" : "NO");
}