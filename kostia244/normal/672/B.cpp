#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	map<char, int> cnt;
	int ans = 0, n;
	cin >> n;
	cin >> s;
	for(auto i : s) cnt[i]++;
	for(auto i : cnt) ans += i.second-1;
	if(s.size()>26)ans=-1;
	cout << ans;
}