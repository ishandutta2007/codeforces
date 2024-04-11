#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 55;
bool prime(int x) {
	for(int i = 2; i * i <= x; i++) if(x%i == 0) return 0;
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	map<int, int> cnt;
	for(auto i : s) cnt[i]++;
	char f = 'a';
	for(auto i : cnt) if(i.second > cnt[f]) f = i.first;
	int c = n;
	string ans(n, '.');
	for(int i = 2; i <= n; i++) {
		if(!(2*i > n && prime(i))) {
			if(cnt[f]--==0) return cout << "NO", 0;
			ans[i-1] = f;
		}
	}	
	for(int i = 1; i <= n; i++) {
		char c = 'a';
		if(i == 1 || (2*i > n && prime(i))) {
		while(!cnt[c]) c++;
			ans[i-1] = c;
			cnt[c]--;
		}
	}
	cout << "YES\n";
	cout << ans;
}