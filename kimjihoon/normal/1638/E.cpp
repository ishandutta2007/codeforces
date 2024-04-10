#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;
long long ss[1000009], ft[1000009];
set<pair<int, int> > st;
bool vs[1000009];

void up(int i, long long w)
{
	while (i <= n) {
		ft[i] += w;
		i += (i & (-i));
	}
}

long long sum(int i)
{
	long long s = 0;
	while (i) {
		s += ft[i];
		i -= (i & (-i));
	}
	return s;
}

void upr(int s, int e, long long w)
{
	up(s, w);
	up(e + 1, -w);
}

void addp(int p, int c)
{
	if (vs[p]) st.erase(st.lower_bound(make_pair(p, 0)));
	else vs[p] = true;
	st.insert(make_pair(p, c));
}

void update(int s, int e, int c)
{
	auto p = st.lower_bound(make_pair(s + 1, 0)), l = p;
	p--;
	while (p != st.end() && p->first <= e) {
		auto nt = p; nt++;
		if (nt == st.end()) upr(max(p->first, s), e, ss[p->second] - ss[c]);
		else {
			upr(max(p->first, s), min(e, nt->first - 1), ss[p->second] - ss[c]);
			if (nt->first <= e) vs[nt->first] = false;
		}
		p = nt;
	}
	p--;
	int rc = p->second;
	p++;
	if (l != st.end()) st.erase(l, p);
	addp(s, c);
	if (e < n && !vs[e + 1]) 
		addp(e + 1, rc);
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int q; cin >> n >> q;
	addp(0, 1);
	for (int i = 0; i < q; i++) {
		string s; cin >> s;
		if (s[0] == 'C') {
			int l, r, c; cin >> l >> r >> c;
			update(l, r, c);
		}
		else if (s[0] == 'A') {
			int c, x; cin >> c >> x;
			ss[c] += x;
		}
		else {
			int p; cin >> p;
			auto sp = st.lower_bound(make_pair(p + 1, 0)); sp--;
			cout << sum(p) + ss[sp->second] << '\n';
		}
	}
	return 0;
}