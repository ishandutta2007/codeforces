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

const int N = 2010;
int n, x[N], y[N];
long long ans;

vector <pair<pair<int, int>, long long>> v;

pair<int, int> slope(int i, int j) {
	int X = x[i] - x[j];
	int Y = y[i] - y[j];
	int g = __gcd(X, Y);
	X /= g;
	Y /= g;
	if(Y < 0) X *= -1, Y *= -1;
	if(X == 0) Y = 1;
	if(Y == 0) X = 1;
	return {X, Y};
}

long long dist(int i, int j) {
	long long X = x[i] - x[j];
	long long Y = y[i] - y[j];
	return X * X + Y * Y;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> x[i] >> y[i];

	for(int i =1 ; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			v.push_back({slope(i, j), dist(i, j)});
			// dbg(i, j, v.back());
		}

	sort(v.begin(), v.end());

	// dbg(v);
	for(int i = 0; i < v.size();) {
		int j = i;
		while(j < v.size() && v[i] == v[j]) j++;
		int d = j - i;
		// dbg(i, j, d);
		i = j;
		ans += d * (d - 1) / 2;
	}


	// for(auto i : m) ans += i.nd * (i.nd - 1) / 2;
	cout << ans / 2 << '\n';
}