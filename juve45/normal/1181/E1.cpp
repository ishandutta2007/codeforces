#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T, class T2> ostream& operator<<(ostream& out, set <T, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n;
map<int, int> m;

struct rect{
	int x1, y1, x2, y2;
} p[N];

class cmp1 {
public:
	bool operator() (int x, int y) {
		if(p[x].x1 == p[y].x1) return x < y;
		return p[x].x1 < p[y].x1;
	}
};
class cmp2 {
public:
	bool operator() (int x, int y) {
		if(p[x].x2 == p[y].x2) return x < y;
		return p[x].x2 > p[y].x2;
	}
};
class cmp3 {
public:
	bool operator() (int x, int y) {
		if(p[x].y1 == p[y].y1) return x < y;
		return p[x].y1 < p[y].y1;
	}
};
class cmp4 {
public:
	bool operator() (int x, int y) {
		if(p[x].y2 == p[y].y2) return x < y;
		return p[x].y2 > p[y].y2;
	}
};

template<class T> 
void put(set <int, T> &s, vector <int> &v, int nr) {
	for(auto i : s)  {
		if(i == nr) break;
		v.push_back(i);
	}
}

bool solve(set <int, cmp1> &s1, set <int, cmp2> &s2, set <int, cmp3> &s3, set <int, cmp4> &s4) {

	int n = s1.size();
	// dbg(n);
	
	// dbg(s1);
	if(n == 1) 
		return 1;

	auto it1 = s1.begin();
	auto it2 = s2.begin();
	auto it3 = s3.begin();
	auto it4 = s4.begin();
	
	int l1 = p[*it1].x2;
	int l2 = p[*it2].x1;
	int l3 = p[*it3].y2;
	int l4 = p[*it4].y1;

	set<int, cmp1> t1;
	set<int, cmp2> t2;
	set<int, cmp3> t3;
	set<int, cmp4> t4;

	vector <int> v;
	int i = 1;
	for(i = 1; i <= n; i++) {
		if(l1 <= p[*it1].x1) {
			put(s1, v, *it1);
			break;
		}

		if(l2 >= p[*it2].x2) {
			put(s2, v, *it2);
			break;
		}

		if(l3 <= p[*it3].y1) {
			put(s3, v, *it3);
			break;
		}

		if(l4 >= p[*it4].y2) {
			put(s4, v, *it4);
			break;
		}

		l1 = max(l1, p[*it1].x2);
		l2 = min(l2, p[*it2].x1);
		l3 = max(l3, p[*it3].y2);
		l4 = min(l4, p[*it4].y1);

		it1++;
		it2++;
		it3++;
		it4++;
	}
	if(i == n + 1) return 0;
	// dbg(s1);
	// dbg(i);

	for(auto i : v) {
		s1.erase(i);
		s2.erase(i);
		s3.erase(i);
		s4.erase(i);
		t1.insert(i);
		t2.insert(i);
		t3.insert(i);
		t4.insert(i);
	}

	return solve(s1, s2, s3, s4) && solve(t1, t2, t3, t4);
}



int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	set <int> s;
	for(int i = 1; i <= n; i++) {
		cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;

		s.insert(p[i].x1);
		s.insert(p[i].y1);
		s.insert(p[i].x2);
		s.insert(p[i].y2);
	}

	int k = 0;
	for(auto i : s) m[i] = ++k;

	for(int i = 1; i <= n; i++) {
		p[i].x1 = m[p[i].x1];
		p[i].y1 = m[p[i].y1];
		p[i].x2 = m[p[i].x2];
		p[i].y2 = m[p[i].y2];
	}

	set<int, cmp1> s1;
	set<int, cmp2> s2;
	set<int, cmp3> s3;
	set<int, cmp4> s4;

	for(int i = 1; i <= n; i++) {
		s1.insert(i);
		s2.insert(i);
		s3.insert(i);
		s4.insert(i);
	}

	cout << (solve(s1, s2, s3, s4) ? "YES" : "NO") << '\n';
}