#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<20;
int to[maxn][26], link[maxn], len[maxn], slink[maxn], diff[maxn], sz, cur;
string s;
void init() {
	len[0] = -1;
	sz = 2, cur = 0;
}
bool bad(int v) {
	return (int)s.size()-len[v]-2 < 0 || s[s.size()-len[v]-2] != s.back();
}
int find_link(int cur) {
	if(!bad(cur)) return cur;
	while(bad(link[cur])) cur = slink[cur];
	return link[cur];
}
vector<array<int, 2>> rollback;
void add(char c) {
	rollback.push_back({cur, -1});
	s += c, c -= 'a';
	cur = find_link(cur); 
	if(!to[cur][c]) {
		rollback.back()[1] = cur;
		len[sz] = len[cur]+2;
		link[sz] = max(1, to[find_link(link[cur])][c]);
		diff[sz] = len[sz] - len[link[sz]];
		slink[sz] = diff[sz] == diff[link[sz]] ? slink[link[sz]] : link[sz];
		to[cur][c] = sz++;
	}
	cur = to[cur][c];
}
void pop() {
	int t = rollback.back()[1];
	if(t != -1) {
		to[t][s.back()-'a'] = 0;
		sz--;
	}
	cur = rollback.back()[0];
	rollback.pop_back();
	s.pop_back();
}
namespace sol {
int d, ge = 0;
string s;
void inc(int pos) {
	if(pos < 0) cout << "Impossible\n", exit(0);
	do {
		pop();
		if(s[pos]++ == 'z') {
			inc(pos-1);
			s[pos] = 'a';
		}
		add(s[pos]);
	} while(len[cur] >= d);
}
void solve() {
	init();
	cin >> d >> s;
	for(auto &i : s) {
		if(ge) i = 'a';
		add(i);
		if(len[cur] >= d) inc(&i-&s[0]), ge = 1;
	}
	if(!ge) inc(s.size()-1);
	cout << s << '\n';
}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	sol::solve();
	return 0;
}