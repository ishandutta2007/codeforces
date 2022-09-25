#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

struct state {
	int len, link, cnt;
	map<char, int> next;

	state() : len(0), link(-1) {}
};

state st[2 * maxn];
int n, last, sz, tim[2 * maxn];
string s, a, b;
vector<int> v[maxn];

/*void extend(char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	st[cur].cnt = 1;
	int p;
	for (p = last; p != -1 && !st[p].next[c]; p = st[p].link)
		st[p].next[c] = cur;
	if (p == -1) {
		st[p].link = 0;
	} else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len) {
			st[cur].link = q;
		} else {
			int clone = sz++;
			st[clone] = st[q];
			st[clone].len = st[p].len + 1;
			for (; p != -1 && st[p].next[c] == q; p = st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}*/

void extend (char c) {
	int cur = ++sz;
	st[cur].cnt = 1;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = ++sz;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			st[clone].cnt = 0;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> s >> n;
	for (int i = 0; i < s.length(); i++)
		extend(s[i]);
	for (int i = 0; i <= sz; i++)
		v[st[i].len].push_back(i);
	for (int i = maxn - 1; i > 0; i--)
		for (int j = 0; j < v[i].size(); j++)
			st[st[v[i][j]].link].cnt += st[v[i][j]].cnt;

	for (int test = 1; test <= n; test++) {
		cin >> a;
		b = a + a; //b.pop_back();
		b.resize(b.size() - 1);
		
		int cur = 0, curlen = 0;
		for (int i = 0; i < a.length(); i++) {
			while (cur != 0 && !st[cur].next[a[i]]) cur = st[cur].link, curlen = min(curlen, st[cur].len);
			cur = st[cur].next[a[i]];
			curlen = min(curlen + 1, st[cur].len);
		}

		ll ans = 0;
		for (int i = 0; i < a.length(); i++) {
			if (curlen == a.length() && !(tim[cur] == test))
				ans += st[cur].cnt, tim[cur] = test;
			if (curlen == a.length()) curlen--;
			if (st[cur].link != -1 && st[st[cur].link].len == curlen)
				cur = st[cur].link;
			if (i == a.length() - 1) break;
			while (cur != 0 && !st[cur].next[b[a.length() + i]]) cur = st[cur].link, curlen = min(curlen, st[cur].len);
			cur = st[cur].next[b[a.length() + i]];
			curlen = min(curlen + 1, st[cur].len);
		}
		cout << ans << endl;
	}

	return 0;
}