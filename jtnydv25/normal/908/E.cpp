#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1005;
string s[N];
map<ll, int> freq;
const int mod = 1e9 + 7;
int C[N][N], B[N];
int main(){
	B[0] = B[1] = 1;
	for(int i = 0; i<N; i++){
		C[i][0] = 1;
		if(i >= 2) B[i] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
			if(i >= 2 && j < i) B[i] = (B[i] + C[i - 1][j] * (ll) B[j]) % mod;
		}
	}

	int m, n;
	cin >> m >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int pos = 0; pos < m; pos++){
		ll mask = 0;
		for(int j = 0; j < n; j++){
			if(s[j][pos] == '1') mask |= (1LL << j);
		}
		freq[mask]++;
	}

	int ans = 1;
	for(auto it : freq){
		// cerr << it.first << " " << it.second << " " <<endl;		
		ans = (ans * (ll) B[it.second]) % mod;
	}
	printf("%d\n", ans);
}