//author: Hexun
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mod = 1000003;
LL a[11][11], b[11];
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
LL f(LL x){
	LL res = 0;
	for(int i = 10; i >= 0; i -= 1){
		res = (res * x + b[i]) % mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i <= 10; i += 1){
		cout << "? " << i << endl;
		cin >> b[i]; 
	}
	for(int i = 0; i <= 10; i += 1)
		for(int j = 0; j <= 10; j += 1)
			a[i][j] = j ? power(i, j) : 1LL;
	for(int i = 0; i <= 10; i += 1){
		int k = -1;
		for(int j = i; j <= 10; j += 1) if(a[j][i] != 0) k = i;
		assert(~k);
		for(int j = i; j <= 10; j += 1) swap(a[k][j], a[i][j]);
		swap(b[k], b[i]);
		LL inv = power(a[i][i], mod - 2);
		for(int j = i; j <= 10; j += 1) a[i][j] = a[i][j] * inv % mod;
		b[i] = b[i] * inv % mod;
		for(int j = i + 1; j <= 10; j += 1){
			LL tmp = a[j][i];
			for(int k = i; k <= 10; k += 1) a[j][k] = (a[j][k] + mod - a[i][k] * tmp % mod) % mod;
			b[j] = (b[j] + mod - b[i] * tmp % mod) % mod;
		}
	}
	for(int i = 10; i >= 0; i -= 1){
		for(int j = i + 1; j <= 10; j += 1){
			b[i] = (b[i] + mod - b[j] * a[i][j] % mod) % mod;
		}
		//cout << i << " " << b[i] << endl;
	}
	for(int i = 0; i < mod; i += 1)
		if(f(i) == 0) {
			cout << "! " << i << endl;
			return 0;
		}
	cout << "! -1";
	return 0;
}

/*
1000002
1000003
1000006
1000011
1000018
1000027
1000038
1000051
1000066
1000083
1000102
*/