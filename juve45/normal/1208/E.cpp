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

const long long N = 1005100;
long long n, w, ans[N], mars[N], l, x;
vector <long long> v;

void proc(vector <long long> & v) {
	deque<long long> d;
	long long l = v.size();
	long long r = max(w - (long long)v.size(), l);

	// dbg(l, r);
	for(long long i = 0; i < l; i++) {
		// dbg(i);
		while(!d.empty() && v[d.back()] < v[i])
			d.pop_back();

		d.push_back(i);
		while(!d.empty() && v.size() - d.front() > w - i)
			d.pop_front();
		
		// 	if(v[d.front()] < 0 && )
		ans[i] += v[d.front()];
	}

	d.clear();
	for(long long i = w - 1; i >= r; i--) {
		long long pos = v.size() - (w - i);
		while(!d.empty() && v[d.back()] < v[pos])
			d.pop_back();

		d.push_back(pos);
		
		ans[i] += v[d.front()];
	}

	long long mx = *max_element(v.begin(), v.end());
	mars[l] += mx;
	mars[r] += -mx;
	d.clear();
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> w;
	w += 2;
	for(long long i = 1; i <= n; i++) {
		cin >> l;
		v.clear();
		v.push_back(0);
		for(long long j = 1; j <= l; j++) {
			cin >> x;
			v.push_back(x);
		}
		v.push_back(0);
		// dbg(v);
		proc(v);
		// dbg_v(ans, w + 1);
		// dbg_v(mars, w + 1);
	}

	
	for(long long i = 1; i < w; i++)
		mars[i] += mars[i - 1];
	for(long long i = 1 ;i + 1 < w; i++)
		cout << ans[i] + mars[i] << ' ';
	return 0;
}