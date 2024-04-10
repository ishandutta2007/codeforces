/* It's not my code. This is kaikey's code */


#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std; typedef unsigned long long _ulong; typedef int lint; typedef long double ld; typedef pair<lint, lint> plint; typedef pair<ld, ld> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;++i)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;--i)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define endk '\n'
#define fi first
#define se second
struct fast_ios { fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
template<class T> auto add = [](T a, T b) -> T { return a + b; };
template<class T> auto f_max = [](T a, T b) -> T { return max(a, b); };
template<class T> auto f_min = [](T a, T b) -> T { return min(a, b); };
template<class T> using V = vector<T>;
using Vl = V<lint>; using VVl = V<Vl>;
template< typename T > ostream& operator<<(ostream& os, const vector< T >& v) {
	for (int i = 0; i < (int)v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : "");
	return os;
}
template< typename T >istream& operator>>(istream& is, vector< T >& v) {
	for (T& in : v) is >> in;
	return is;
}
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
lint gcd(lint a, lint b) { if (b == 0) return a; else return gcd(b, a % b); }
lint ceil(lint a, lint b) { return (a + b - 1) / b; }
lint digit(lint a) { return (lint)log10(a); }
lint e_dist(plint a, plint b) { return abs(a.fi - b.fi) * abs(a.fi - b.fi) + abs(a.se - b.se) * abs(a.se - b.se); }
lint m_dist(plint a, plint b) { return abs(a.fi - b.fi) + abs(a.se - b.se); }
void Worshall_Floyd(VVl& g) { REP(k, SZ(g)) REP(i, SZ(g)) REP(j, SZ(g)) chmin(g[i][j], g[i][k] + g[k][j]); }
const lint MOD1000000007 = 1000000007, MOD998244353 = 998244353, INF = 1e18;
lint dx[8] = { 1, 0, -1, 0, 1, -1, 1, -1 }, dy[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
bool YN(bool flag) { cout << (flag ? "YES" : "NO") << endk; return flag; } bool yn(bool flag) { cout << (flag ? "Yes" : "No") << endk; return flag; }
struct Edge {
	lint from, to;
	lint cost;
	Edge() {
 
	}
	Edge(lint u, lint v, lint c) {
		cost = c;
		from = u;
		to = v;
	}
	bool operator<(const Edge& e) const {
		return cost < e.cost;
	}
};
struct WeightedEdge {
	lint to;
	lint cost;
	WeightedEdge(lint v, lint c = 1) {
		to = v;
		cost = c;
	}
	bool operator<(const WeightedEdge& e) const {
		return cost < e.cost;
	}
};
using WeightedGraph = V<V<WeightedEdge>>;
typedef pair<plint, lint> tlint;
typedef pair<plint, plint> qlint;
typedef pair<char, lint> valchar;
 
int main() {
 
	Vl x_cnt(1001), y_cnt(1001); // this part is different than original one.
	set<plint> st;
	lint curr_x, curr_y;
	cin >> curr_x >> curr_y;
	Vl X(666), Y(666);
	REP(i, 666) {
		cin >> X[i] >> Y[i];
		x_cnt[X[i]]++;
		y_cnt[Y[i]]++;
		st.insert({ X[i], Y[i] });
	}
	REP(_, 2) {
		while (curr_x != 500 || curr_y != 500) { // this part is different than original one.
			lint nx = 500, ny = 500;
			if(curr_x!=500) nx = curr_x + (500 - curr_x) / abs(500 - curr_x);
			if(curr_y!=500) ny = curr_y + (500 - curr_y) / abs(500 - curr_y); // this part is different than original one.
			if (st.count({ nx, ny })) {
				ny -= (500 - curr_y) / abs(500 - curr_y);
			}
			cout << nx << " " << ny << endl;
			curr_x = nx, curr_y = ny;
			if (x_cnt[nx] || y_cnt[ny]) return 0;
			lint k, x, y;
			cin >> k >> x >> y; k--;
			x_cnt[X[k]]--;
			y_cnt[Y[k]]--;
			st.erase({ X[k], Y[k] });
			X[k] = x;
			Y[k] = y;
			x_cnt[X[k]]++;
			y_cnt[Y[k]]++;
			st.insert({ X[k], Y[k] });
		}
		lint dir_x = -1, dir_y = -1;
		REP(k, 4) {
			lint sum = 0;
			REP(i, 666) {
				if (k == 0) sum += (X[i] <= 499 || Y[i] <= 499);
				if (k == 1) sum += (X[i] >= 501 || Y[i] <= 499);
				if (k == 2) sum += (X[i] <= 499 || Y[i] >= 501);
				if (k == 3) sum += (X[i] >= 501 || Y[i] >= 501);
			}
			if (sum >= 500) { // this part is different than original one.
				if (k == 0) dir_x = -1, dir_y = -1;
				if (k == 1) dir_x = 1, dir_y = -1;
				if (k == 2) dir_x = -1, dir_y = 1;
				if (k == 3) dir_x = 1, dir_y = 1;
				break;
			}
		}
		while (true) {
			lint nx = curr_x + dir_x, ny = curr_y + dir_y;
			if (nx <= 0 || nx > 999 || ny <= 0 || ny > 999) break;
			if (st.count({ nx, ny })) {
				nx -= dir_x;
			}
			cout << nx << " " << ny << endl;
			curr_x = nx, curr_y = ny;
			if (x_cnt[nx] || y_cnt[ny]) return 0;
			lint k, x, y;
			cin >> k >> x >> y; k--;
			x_cnt[X[k]]--;
			y_cnt[Y[k]]--;
			st.erase({ X[k], Y[k] });
			X[k] = x;
			Y[k] = y;
			x_cnt[X[k]]++;
			y_cnt[Y[k]]++;
			st.insert({ X[k], Y[k] });
		}
	}
}