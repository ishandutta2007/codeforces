#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 50;
const int mod = 1e9 + 7;


int n, m;

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

lint fact(int x){
	lint ret = 1;
	for(int i=1; i<=x; i++) ret = ret * i % mod;
	return ret;
}

lint bino(int x, int y){
	return fact(x) * ipow(fact(x - y) * fact(y) % mod, mod - 2) % mod;
}

int main(){
	cin >> n >> m;
	cout << bino(n + 2 * m - 1, 2 * m) << endl;
}