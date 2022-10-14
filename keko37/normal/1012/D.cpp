#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef pair <int, char> par;

const int MAXN = 200005;

int n, m, sign;
string s, t;
deque <par> a, b;
vector <pair <int, int> > v;

int val (par x, par y) {
	if (x.first == y.first && x.second == y.second) return x.first; return max(x.first, y.first) - 1;
}

par pref (par x, int len) {
	return make_pair(len, x.second);
}

par suf (par x, int len) {
	if (len == 0) return x;
	if (len & 1) return make_pair(x.first - len, x.second == 'a' ? 'b' : 'a');
	return make_pair(x.first - len, x.second);
}

par spoji (par x, par y) {
	if (x.first == 0) return y;
	char c;
	if (x.first & 1) c = x.second; else c = x.second == 'a' ? 'b' : 'a';
	return make_pair(x.first + y.first - (c == y.second), x.second);
}

void update (int x, int y) {
	vector <par> ra, rb;
	int lena = 0, lenb = 0;
	for (int i=0; i<x; i++) {
		lena += a.front().first;
		ra.push_back(a.front());
		a.pop_front();
	}
	for (int i=0; i<y; i++) {
		lenb += b.front().first;
		rb.push_back(b.front());
		b.pop_front();
	}
	if (rb.size() >= 1 && a.size() >= 1) {
		par kraj = rb.back();
		if (kraj.second == a.front().second) {
			kraj.first += a.front().first;
			a.pop_front();
			rb.pop_back();
			rb.push_back(kraj);
		}
	}
	if (ra.size() >=1 && b.size() >= 1) {
		par kraj = ra.back();
		if (kraj.second == b.front().second) {
			kraj.first += b.front().first;
			b.pop_front();
			ra.pop_back();
			ra.push_back(kraj);
		}
	}
	for (int i = (int) ra.size()-1; i>=0; i--) {
		b.push_front(ra[i]);
	}
	for (int i = (int) rb.size()-1; i>=0; i--) {
		a.push_front(rb[i]);
	}
	v.push_back(make_pair(lena, lenb));
}

void izjednaci () {
	n = a.size(), m = b.size();
	pair <int, int> p;
	int sol = MAXN;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<2; j++) {
			par p1 = spoji(pref(make_pair(b.size(), b.front().second), j), suf(make_pair(a.size(), a.front().second), i));
			par p2 = spoji(pref(make_pair(a.size(), a.front().second), i), suf(make_pair(b.size(), b.front().second), j));
			int novi = val(p1, p2);
			if (novi < sol) {
				sol = novi;
				p = make_pair(i, j);
			}
		}
	}
	update(p.first, p.second);
}

void rjesi () {
	while (1) {
		if (a.size() == 1 && b.size() == 1 && a.front().second != b.front().second) break;
		if (a.size() < b.size()) {
			swap(a, b);
			sign = !sign;
		}
		if (a.size() - b.size() >= 2) {
			izjednaci();
		} else if (a.front().second == b.front().second) {
			update(1, 0);
		} else {
			update(1, 1);
		}
		if (sign) {
			pair <int, int> p = v.back();
			v.pop_back();
			v.push_back(make_pair(p.second, p.first));
		}
	}
}

int main () {
	cin >> s >> t;
	s += '.'; t += '.';
	n = s.size(); m = t.size();
	int cnt = 1;
	for (int i=1; i<n; i++) {
		if (s[i] == s[i-1]) {
			cnt++;
		} else {
			a.push_back(make_pair(cnt, s[i-1]));
			cnt = 1;
		}
	}
	for (int i=1; i<m; i++) {
		if (t[i] == t[i-1]) {
			cnt++;
		} else {
			b.push_back(make_pair(cnt, t[i-1]));
			cnt = 1;
		}
	}
	rjesi();
	cout << v.size() << endl;
	for (int i=0; i<v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}