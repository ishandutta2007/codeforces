#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 2e5 + 55, mod = 1e9 + 7;
string s, t;
int p[maxn], suf[maxn];
int last[maxn][26];
void setup() {
	memset(last, -1, sizeof last);
	for(int i = 0; i < t.size(); i++)
		last[i][t[i]-'a'] = i;
	for(int i = 1; i <= t.size(); i++) {
		for(int j = 0; j < 26; j++) {
			last[i][j] = max(last[i][j], last[i-1][j]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	setup();
	int n = s.size(), m = t.size();
	for(int i = 0; i < n; i++) {
		if(i) p[i] = p[i-1];
		if(p[i] < t.size() && t[p[i]] == s[i]) p[i]++;
	}
	reverse(all(s));
	reverse(all(t));
	for(int i = 0; i < n; i++) {
		if(i) suf[i] = suf[i-1];
		if(suf[i] < t.size() && t[suf[i]] == s[i]) suf[i]++;
	}
	reverse(suf, suf+n);
	reverse(all(s));
	reverse(all(t));
	int pos = 0;
	for(int i = 0; i < n; i++) {
		if(!p[i])  return cout << "No", 0;
		pos = last[p[i]-1][s[i]-'a']+1;
		if(i+1==n) {
			if(pos < t.size())  return cout << "No", 0;
		} else {
			if(!suf[i+1] || !pos || pos + suf[i+1] < t.size())  return cout << "No", 0;
		}
	}
	cout << "Yes\n";
}