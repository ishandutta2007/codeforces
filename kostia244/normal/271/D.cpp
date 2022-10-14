#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
char c;
int g[5000000][26], pref[1505], n = 0, st, k;
bool bad[26];
string s;

inline int cost(int i) {
	return pref[i] - (st ? pref[st-1] : 0);
}

void add(int v, int pos) {
	if(pos == s.size() || cost(pos) > k)
		return;
	if(v >= 5000000)
		exit(5);
	if(g[v][s[pos]-'0'] == 0)
		g[v][s[pos]-'0'] = ++n;
	add(g[v][s[pos]-'0'], pos+1);
}

int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> s;
	for(int i = 0; i < 26; i++) cin >> c, bad[i] = (c-'0')^1;
	pref[0] = bad[s[0]-'a'];
	for(int i = 1; i < s.size(); i++) pref[i] = bad[s[i]-'a'] + pref[i-1];
	pref[s.size()] = pref[s.size()-1];
	cin >> k;
	for(st = 0; st < s.size(); st++) {
		add(0, st);
	}
	cout << n;
}