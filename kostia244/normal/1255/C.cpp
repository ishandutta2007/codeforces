//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
int n;
map<int, int> cnt[100100], cc;
void add(int a, int b, int c) {
	cc[a]++;
	cc[b]++;
	cc[c]++;
	cnt[a][b]++;
	cnt[a][c]++;
	cnt[b][a]++;
	cnt[b][c]++;
	cnt[c][a]++;
	cnt[c][b]++;
}
void rem(int x) {
	for(auto i : cnt[x])
		cc[i.first]--;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int a, b, c, i = 2; i < n; i++) {
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int st = -1, en;
	for (auto i : cc)
		if (i.second == 1) {
			if (st == -1)
				st = i.first;
			else
				en = i.first;
		}
	int s2 = -1, en2;
	for (auto i : cc)
		if (i.second == 2) {
			if (s2 == -1)
				s2 = i.first;
			else
				en2 = i.first;
		}
	if(!cnt[st].count(s2)) swap(s2, en2);
	add(en, st, s2);
	add(en2, en, st);
	cout << st << " " << s2 << " ";
	set<int> used;
	used.insert(st);
	used.insert(s2);
	used.insert(en2);
	used.insert(en);
	rem(st);
	rem(s2);
	int x = s2;
	while(x!=-1) {
		int nn = -1;
		for(auto i : cnt[x]) {
//			cout << i.first << " " << cc[i.first] << "\n";
			if(cc[i.first]==1&&i.first!=en2&&i.first!=en&&i.first!=s2&&i.first!=st) {
				nn=i.first;
				break;
			}
		}
		if(nn==-1) break;
		x = nn;
		rem(x);
		cout << x << " ";
	}
	cout << en2 << " " << en;
}