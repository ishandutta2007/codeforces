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
int n, r, g, b;

int ans1(int r, int g, int b) {
	int ret = 0;
	ret += r / 3;
	ret += g / 3;
	ret += b / 3;
	r %= 3;
	g %= 3;
	b %= 3;
	return ret + min({r, b, g});
}


int ans2(int r, int g, int b) {
	int must = min({r, b, g});
	r -= must;
	g -= must;
	b -= must;
	return must + r / 3 + g / 3 + b / 3;
}

int ans3(int r, int g, int b) {
	int must = min({r, b, g});
	must = max(must - 1, 0);
	r -= must;
	g -= must;
	b -= must;
	return must + r / 3 + g / 3 + b / 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> r >> g >> b;

	cout << max({ans1(r, g, b), ans2(r, g, b), ans3(r, g, b)});
}