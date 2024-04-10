#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, multiset <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n, k, l, r;

vector <int> ans;
vector <pair<pair<int, int>, int > > v;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		cin >> l >> r;
		v.push_back({{r, l}, i});
	}

	sort(v.begin(), v.end());

	multiset <int> last;
	for(int i = 0; i < k; i++) last.insert(0);

	for(auto i : v) {
		// dbg(i);
		// dbg(last);
		auto it = last.lower_bound(i.st.nd);
		if(it == last.begin()) {
			ans.push_back(i.nd);
			continue;
		}
		it--;
		last.erase(it);
		last.insert(i.st.st);
	}

	cout << ans << '\n';
}