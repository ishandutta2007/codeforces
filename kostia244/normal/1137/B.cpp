//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	vi b;
	cin >> s >> t;
	b.resize(t.size()+1);
	int i = 0, j = -1;
	b[0]=-1;
	while(i < t.size()) {
		while(j!=-1&&t[j]!=t[i]) j = b[j];
		i++, j++;
		b[i] = j;
	}
	int cnt[2] = {0, 0};
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'0']++;
	int k = 0;
	for(int i = 0; i < s.size(); i++) {
		if(k==t.size()) k = b[k];
		if(cnt[t[k]-'0']) cout << t[k], cnt[t[k]-'0']--, k++;
		else break;
	}
	while(cnt[0]--) cout << '0';
	while(cnt[1]--) cout << '1';
}