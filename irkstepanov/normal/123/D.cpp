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
	int num;
	node() : link(-1), len(0), num(0) {}
};

vector<node> t;
int last = 0;

void add(char c) {
	int curr = sz(t);
	t.pb(node());
	t[curr].len = t[last].len + 1;
	int p = last;
	while (p != -1 && !t[p].to.count(c)) {
		t[p].to[c] = curr;
		p = t[p].link;
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
	t[clone].len = t[p].len + 1;
	t[clone].link = t[q].link;
	t[clone].to = t[q].to;
	t[curr].link = clone;
	t[q].link = clone;
	last = curr;
	while (p != -1 && t[p].to[c] == q) {
		t[p].to[c] = clone;
		p = t[p].link;
	}
}

int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
                                               
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    t.pb(node());
    string s;
    cin >> s;
    for (int i = 0; i < sz(s); ++i) {
    	add(s[i]);
    }

    vector<int> order;
    for (int v = 0; v < sz(t); ++v) {
    	order.pb(v);
    }

    sort(all(order), [&] (int u, int v) { return t[u].len < t[v].len; });
    reverse(all(order));

    int tmp = order[0];
    ++t[tmp].num;
    while (true) {
    	tmp = t[tmp].link;
    	if (tmp == -1) {
    		break;
    	}
    	++t[tmp].num;
    }

    for (int v : order) {
    	//cout << "!" << v << endl;
    	for (auto it : t[v].to) {
    		t[v].num += t[it.second].num;
    	}
    }

    ll ans = 0;
    for (int v = 1; v < sz(t); ++v) {
    	int cnt = t[v].len - t[t[v].link].len;
    	//cout << v << " " << t[v].num << " " << t[v].link << endl;
    	ans += ll(cnt) * t[v].num * (t[v].num + 1) / 2;
    }
    cout << ans << "\n";

}