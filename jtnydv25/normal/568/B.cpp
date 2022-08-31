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

const int N = 4005;
int C[N][N], bell[N];

inline int ans(int n){
	int ret = 0;
	for(int r = 0; r < n; r ++) ret = add(ret, mul(C[n][r], bell[r]));
	return ret;
}
int main(){
	bell[0] = bell[1] = 1;
	for(int i = 0; i < N; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		if(i >= 2){
			for(int j = 0; j < i; j ++) bell[i] = add(bell[i], mul(C[i - 1][j], bell[j]));
		}	
	}
	int n;
	cin >> n;
	cout << ans(n) << endl;
}