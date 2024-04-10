#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
double a, b, c;

double dist(pair<double, double> a, pair<double, double> b) {
	double x = a.st - b.st;
	double y = a.nd - b.nd;
	return sqrt(x * x + y * y);
}

int main() {
	ios_base::sync_with_stdio(false);


	pair<double, double> A, B, A1, A2, B1, B2;
	cin >> a >> b >> c;
	cin >> A.st >> A.nd;
	cin >> B.st >> B.nd;

	double ans = abs(A.st - B.st) + abs(A.nd - B.nd);


	A1.st = A.st;
	A1.nd = 1. * (-c - a * A1.st) / b;

	A2.nd = A.nd;
	A2.st = 1. * (-c - b * A2.nd) / a;

	B1.st = B.st;
	B1.nd = 1. * (-c - a * B1.st) / b;

	B2.nd = B.nd;
	B2.st = (-c - b * B2.nd) / a;

	// dbg(A1, A2);
	// dbg(B1, B2);
	// dbg(dist(A, A2), dist(A2, B1), dist(B1, B));
	// dbg(dist(A, A2), dist(A2, B2), dist(B2, B));


	ans = min(ans, dist(A, A1) + dist(A1, B1) + dist(B1, B));
	ans = min(ans, dist(A, A1) + dist(A1, B2) + dist(B2, B));
	ans = min(ans, dist(A, A2) + dist(A2, B1) + dist(B1, B));
	ans = min(ans, dist(A, A2) + dist(A2, B2) + dist(B2, B));
	cout << fixed << setprecision(8) << ans << '\n';
}