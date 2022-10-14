//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	char x = 'T';
	map<char, int> cnt;
	for(auto i : s)
		cnt[i]++;
	ll ans = 1;
	for(auto i : "ACG")
		if(cnt[i] > cnt[x]) x = i, ans = 1;
		else if(cnt[i] == cnt[x]) ans++;
	ll r = 1;
	for(int i = 0; i < n; i++)
		r = (r*ans)%mod;
	cout << r;
}