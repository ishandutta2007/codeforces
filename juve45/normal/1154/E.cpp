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
int n, k, a[N], use[N];
set <int> s;
priority_queue <pair<int, int>> pq;


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(i);
		pq.push({a[i], i});
	}

	int who = 1;

	for(; !pq.empty(); pq.pop(), who = 3 - who) {
		int x = pq.top().nd;
		if(use[x]) {
			who = 3 - who;
			continue;
		}
		use[x] = who;
		vector <int> choose;
		auto it = s.find(x);
		for(int i = 0; i <= k; i++) {
			choose.push_back(*it);
			if(it == s.begin()) break;
			it--;
		}
		it = s.find(x);
		for(int i =0; i < k; i++) {
			it++;
			if(it == s.end()) break;
			choose.push_back(*it);
		}
		for(auto i : choose) {
			use[i] = who;
			s.erase(i);
		}
	}

	for(int i = 1; i <= n; i++) cout << use[i];
}