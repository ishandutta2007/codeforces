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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"



long long n, k, m, a, b, x, y;
string s;

bool can(pair<long long, long long> st, pair<long long, long long> fi, pair <long long, long long> step) {
	dbg(st, fi, step);
	if(step.st * (fi.st - st.st) < 0) return false;
	if(step.nd * (fi.nd - st.nd) < 0) return false;
	if(step.st == 0) {
		if(step.nd == 0) {
			return (st == fi);
		} else {
			if(st.st != fi.st) return 0;
			long long req = (fi.nd - st.nd) / step.nd;
			return (step.nd * req + st.nd == fi.nd);
		}
	} else if(step.nd == 0){
		if(st.nd != fi.nd) return 0;
		long long req = (fi.st - st.st) / step.st;
		return (step.st * req + st.st == fi.st);
	}


	long long req = (fi.nd - st.nd) / step.nd;
	return ((step.nd * req + st.nd == fi.nd) && (step.st * req + st.st == fi.st));
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> x >> y;
	cin >> s;

	long long xf = x, xs = 0;
	long long yf = y, ys = 0;
	x = y = 0;

	for(auto i : s) {
		if(i == 'L') x--;
		else if(i == 'R') x++;
		else if(i == 'U') y++;
		else y--;
	}

	if(can({xs, ys}, {xf, yf}, {x, y}))
			return cout << "Yes\n", 0;

	dbg(x, y);
	for(auto i : s) {
		if(i == 'L') xs--;
		else if(i == 'R') xs++;
		else if(i == 'U') ys++;
		else ys--;

		if(can({xs, ys}, {xf, yf}, {x, y}))
			return cout << "Yes\n", 0;
	}
	cout << "No\n";
}