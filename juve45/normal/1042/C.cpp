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

const int N = 200100;
int n, a[N], z[N];
vector <int> pos, neg, zero;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < 0) neg.push_back(i);
		if(a[i] == 0) zero.push_back(i), z[i] = 1;
		if(a[i]> 0) pos.push_back(i);
	}
	// dbg(neg);
	// dbg(zero);
	if((zero.size() == 0 && (neg.size() % 2 == 0)) ||(neg.size() == 1 && zero.size() == n - 1)) {
		// dbg_ok;
		for(int i = 2; i <= n; i++)
			cout << "1 " << i << " 1\n";
		return 0;
	}
	if(zero.size()) {
		dbg_ok;
		if(neg.size() % 2 == 1) {
			int cand = neg[0];
			for(auto i : neg)
			if(a[i] > a[cand])
				cand = i;
			zero.push_back(cand);
			z[cand] = 1;
			dbg(cand);
			neg.erase(find(neg.begin(), neg.end(), cand	));
		}
		int to = n;
		if(pos.size()) to = pos[0];
		else if(neg.size())to = neg[0];

		for(int i = 1; i <= n; i++) {
			if(i == to) continue;
			if(i == zero[0]) continue;
			if(z[i]) cout << "1 " << i << ' ' << zero[0] << '\n';
			else cout << "1 " << i << ' ' << to << '\n';
		}
		cout << "2 " << zero[0] << '\n';
		return 0;
	}

	int cand = 0;
	if(neg.size() > 0) cand = neg[0];
	for(auto i : neg)
		if(a[i] > a[cand])
			cand = i;

	int to = 1;
	if(to == cand) to = n;

	for(int i = 1; i <= n; i++) {
		if(i == to) continue;
		if(i == cand) cout << "2 " << i << '\n';
		else cout << "1 " << i << ' ' << to << '\n';
	}
	return 0;

}