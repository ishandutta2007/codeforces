#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct node {
	int link;
	int len;
	map<char, int> to;
	int good;
	node() : link(-1), len(0), good(0) {}
};

vector<node> t;
int last = 0;

void add(char c, int flag) {
	int curr = sz(t);
	t.pb(node());
	t[curr].len = t[last].len + 1;
	t[curr].good = flag;
	int p = last;
	while (p != -1) {
		if (!t[p].to.count(c)) {
			t[p].to[c] = curr;
			p = t[p].link;
		} else {
			break;
		}
	}
	if (p == -1) {
		t[curr].link = 0;
		last = curr;
		return;
	}
	int q = t[p].to[c];
	if (t[q].len == t[p].len + 1) {
		t[curr].link = q;
		last = curr;
		return;
	}
	int clone = sz(t);
	t.pb(node());
	t[clone].to = t[q].to;
	t[clone].len = t[p].len + 1;
	t[clone].link = t[q].link;
	while (p != -1) {
		if (t[p].to.count(c) && t[p].to[c] == q) {
			t[p].to[c] = clone;
			p = t[p].link;
		} else {
			break;
		}
	}
	t[q].link = t[curr].link = clone;
	last = curr;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	t.pb(node());
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;
	for (int i = 0; i < n; ++i) {
		add(a[i], (b[i] == '0'));
	}

	vector<int> ord;
	for (int i = 1; i < sz(t); ++i) {
		ord.pb(i);
	}
	sort(all(ord), [&] (int a, int b) {
		return t[a].len > t[b].len;
	});
	for (int v : ord) {
		t[t[v].link].good += t[v].good;
	}

	ll ans = 0;
	for (int v = 1; v < sz(t); ++v) {
		ans = max(ans, ll(t[v].good) * ll(t[v].len));
	}
	cout << ans << "\n";

}