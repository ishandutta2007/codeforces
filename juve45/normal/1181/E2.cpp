#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }

class nod;


const int N = 200100;
int n;
map<int, int> m;

struct rect{
	int x1, y1, x2, y2;
} p[N];

class nod{
public:
	int l, r, i;
	nod(int _l, int _r, int _i) {r = _r, l = _l, i = _i;}
	bool operator<(const nod & a) const {
		if(a.l == l) return i < a.i;
		return l < a.l;
	}
	bool operator==(nod & a) {
		return l == a.l && r == a.r && i == a.i;
	}
};
ostream& operator<<(ostream& out, nod n) { return out << "(" << n.l << ", " << n.r << ", " << n.i << ")"; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


set <nod> s[4];

void put(set <nod> &s, vector <int> &v, nod nr) {
	for(auto i : s) {
		if(i == nr) return;
		v.push_back(i.i);
	}
}

bool solve(set <nod> s[4]) {

	int n = s[0].size();
	if(n == 1) return 1;

	int l[4];
	set<nod> :: iterator it[4];

	for(int i = 0; i < 4; i++) {
		it[i] = s[i].begin();
		l[i] = it[i]->r;
	}

	set<nod> t[4];
	vector <int> v;

	int i = 1, ok = 0;
	for(i = 1; i <= n && !ok; i++) {
		for(int j = 0; j < 4; j++) {
			if(l[j] <= it[j]->l) {
				put(s[j], v, *it[j]);
				ok = 1;
				break;
			}
			l[j] = max(l[j], it[j]->r);
			it[j]++;
		}
		if(ok) break;
	}

	if(i == n + 1) return 0;

	for(auto i : v) {
		int j = i;

		s[0].erase(nod(p[j].x1, 	p[j].x2, i));
		s[1].erase(nod(-p[j].x2, -p[j].x1, i));
		s[2].erase(nod(p[j].y1, 	p[j].y2, i));
		s[3].erase(nod(-p[j].y2, -p[j].y1, i));

		t[0].insert(nod(p[j].x1, 	p[j].x2, i));
		t[1].insert(nod(-p[j].x2, -p[j].x1, i));
		t[2].insert(nod(p[j].y1, 	p[j].y2, i));
		t[3].insert(nod(-p[j].y2, -p[j].y1, i));
	}
	return solve(s) && solve(t);
}



int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	set <int> ss;
	for(int i = 1; i <= n; i++)
		cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;

	set<nod> s[4];

	for(int i = 1; i <= n; i++) {
		s[0].insert({p[i].x1, 	p[i].x2, i});
		s[1].insert({-p[i].x2, -p[i].x1, i});
		s[2].insert({p[i].y1, 	p[i].y2, i});
		s[3].insert({-p[i].y2, -p[i].y1, i});
	}

	cout << (solve(s) ? "YES" : "NO") << '\n';
}