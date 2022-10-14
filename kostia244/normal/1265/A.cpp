//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7*17*(1<<23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(int i = 0) {
	string s;
	cin >> s;
	s = "a"+s+"a";
	for(int i = 1; i+1 < s.size(); i++) {
		if(s[i] != '?') continue;
		if(s[i-1]==s[i+1]||s[i+1]=='?') {
			int t = s[i-1]-'a';
			s[i] = char('a' + (t+1)%3);
		} else {
			s[i] = 'a'^'b'^'c'^s[i-1]^s[i+1];
		}
	}
	int ok = 1;
	for(int i = 1; i +2 < s.size(); i++)
		ok &= s[i]!=s[i+1];
	if(!ok) {
		cout << "-1\n";
		return;
	}
	for(int i = 1; i + 1 < s.size(); i++)
		cout << s[i];
	cout << "\n";
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}