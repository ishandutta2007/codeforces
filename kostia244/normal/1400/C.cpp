#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 222, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		int x;
		cin >> s >> x;
		string ans(s.size(), '1');
		int n = s.size();
		for(int i = 0; i < n; i++) if(s[i] == '0') {
			if(i-x >= 0) ans[i-x] = '0';
			if(i+x < n) ans[i+x] = '0';
		}
		int bad = 0;
		for(int i = 0; i < n; i++) {
			int one = 0;
			if(i-x >= 0) one |= ans[i-x] == '1';
			if(i+x < n) one |= ans[i+x] == '1';
			if(s[i] != ('0'+one)) bad = 1;
		}
		cout << (bad?"-1":ans) << '\n';
	}
}