#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pci;
struct comp {bool operator()(const pci&a, const pci&b) { if (a.first > b.first)return 1; if (a.first == b.first&&a.second < b.second)return 1; return 0; } };
priority_queue<pci, vector<pci>, comp> pq;
bool op[1000000],rem[1000000];
char nex[1000000];
int main() {
	int n,m,i,j;
	string s,t,u;
	scanf("%d", &m);
	cin >> s;
	n = s.size();
	int it = 0;
	int np;
	if (m == 1) {
		sort(s.begin(), s.end());
		cout << s;
		getchar(); getchar();
		return 0;
	}
	for (i = 0; i <= n - m;) {
		for (; it < i + m; it++)pq.push(make_pair(s[it], it));
		while (pq.top().second < i)pq.pop();
		char bes = pq.top().first;
		 np = pq.top().second+1;
		t.push_back(bes);
		pq.pop();
		while ((!pq.empty())&&pq.top().first == bes) {
			if(pq.top().second>=i)t.push_back(bes), op[t.size() - 1] = 1;
			pq.pop();
		}
		i = np;
	}
	char wor = 1;
	for (char c : t)wor = max(wor, c);
	for (char c : s)if (c < wor)u.push_back(c);
	sort(u.begin(), u.end());
	cout << u;
	for (i = 0; i < t.size(); i++)if (t[i] == wor && (!op[i]))printf("%c", t[i]);
	getchar(); getchar();
}