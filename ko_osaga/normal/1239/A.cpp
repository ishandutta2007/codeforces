#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
const int mod = 1e9 + 7;
const int MAXN = 500005;
lint f[MAXN];

int main(){
	f[0] = f[1] = 1;
	for(int i=2; i<MAXN; i++){
		f[i] = (f[i-1] + f[i-2]) % mod;
	}
	int n, m; cin >> n >> m;
	cout << (f[n] + f[m] + mod - 1) * 2ll % mod << endl;
}