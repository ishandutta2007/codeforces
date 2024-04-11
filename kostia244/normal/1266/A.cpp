#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
void solve() {
	string s;
	map<char, int> cnt;
	int a = 0;
	cin >> s;
	for(auto i : s) {
		cnt[i]++;
		a += i-'0';
	}
	if(cnt['0']==0) {
		cout << "cyan\n";
		return;
	}
	cnt['0']--;
	bool ok = (cnt['0']||cnt['2']||cnt['4']||cnt['6']||cnt['8'])&&(a%3==0);
	cout << (ok?"red":"cyan") << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}