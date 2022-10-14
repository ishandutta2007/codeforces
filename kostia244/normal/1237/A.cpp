#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define apply fuckstl
using namespace std;
using ll = int64_t;
const int maxn = 1<<25, mod = 1e9 + 7, B = 23000, R = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> s(n);
	int S = 0;
	for(auto &i : s) {
		cin >> i[0];
		if(i[0]%2) {
			i[1]++, i[0]--;
		}
		i[0] /= 2;
		S += i[0];
	}
	for(auto &i : s) if(i[1] && S < 0) i[0]++, S++;
	for(auto &i : s) cout << i[0] << '\n';
}