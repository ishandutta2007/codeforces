#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_SUFFIX_AUTOMATON_SIZE = 10005;

struct node {
	int link, len, first_occ;
	map<char, int> next;
} b[MAX_SUFFIX_AUTOMATON_SIZE]; int sz, last;

void extend(char c) {
	int curr = sz++;
	b[curr].len = b[last].len + 1;
	b[curr].first_occ = b[curr].len;
	int p = last;
	while (p != -1 && b[p].next.count(c) == 0) {
		b[p].next[c] = curr;
		p = b[p].link;
	}

	if (p == -1) {
		b[curr].link = 0;
	} else {
		int q = b[p].next[c];
		if (b[p].len + 1 == b[q].len) {
			b[curr].link = q;
		} else {
			int clone = sz++;
			b[clone].next = b[q].next;
			b[clone].link = b[q].link;
			b[clone].len = b[p].len + 1;
			b[clone].first_occ = b[q].first_occ;
			while (p != -1 && b[p].next[c] == q) {
				b[p].next[c] = clone;
				p = b[p].link;
			}
			b[curr].link = b[q].link = clone;
		}
	}
	last = curr;
}

basic_string<int> topo() {
	basic_string<int> a(sz, 0);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&](int i, int j) {
		return b[i].len < b[j].len;
	});
	return a;
}

int n, aa, bb;
string s;
bool e[5005][5005];
int dp[5005];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> aa >> bb >> s;
	b[0].link = -1;
	sz = 1;
	for (int i=0; i<n; i++)
		extend(s[i]);

	for (int l=0; l<n; l++) {
		int sa_node = 0;
		for (int r=l+1; r<=n; r++) {
			if (b[sa_node].next.count(s[r-1]) == 0)
				break;
			sa_node = b[sa_node].next[s[r-1]];
			e[l][r] = b[sa_node].first_occ <= l;
		}
	}

	memset(dp, 63, sizeof(dp));
	dp[0] = 0;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (e[i][j]) {
				dp[j] = min(dp[j], dp[i] + bb);
			}
			if (j == i+1)
				dp[j] = min(dp[j], dp[i] + aa);
		}
	}

	cout << dp[n] << '\n';
}