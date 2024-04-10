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

const int N = 100100;
const int B = 37;
const int MOD1 = 1e9 + 7;
const int MOD2 = 997344677;

int n, k, pb1[N], pb2[N], val[N], pal[N], inp[N];
pair <int, int> fh[N], rh[N];
map <pair<int, int>, deque<int> > m;
vector <pair<int, int> > v, prs;
string s;

pair<int, int> geth(string s) {
	int h1 = 0, h2 = 0;
	for(int i = 0; i < s.size(); i++) {
		h1 = (h1 * B + s[i] - 'a' + 1) % MOD1;
		h2 = (h2 * B + s[i] - 'a' + 1) % MOD1;
	}
	return {h1, h2};
}


int main() {
	ios_base::sync_with_stdio(false);


	cin >> n >> k;
	pb1[0] = 1;
	pb2[0] = 1;
	for(int i = 1; i <= k; i++) {
		pb1[i] = pb1[i - 1] * B % MOD1;
		pb2[i] = pb2[i - 1] * B % MOD2;
	}

	for(int i= 1; i <= n; i++) {
		cin >> s >> val[i];

		fh[i] = geth(s);
		reverse(s.begin(), s.end());
		rh[i] = geth(s);

		if(fh[i] == rh[i]) pal[i] = 1;

		v.push_back({val[i], i});
	}

	sort(v.begin(), v.end(), greater <pair<int, int>>());

	int ans = 0;

	for(auto i : v) {
		if(m.count(rh[i.nd]) && m[rh[i.nd]].size() > 0) {
			int x = m[rh[i.nd]].front();
			int y = i.nd;
			// dbg(x, y);
			if(val[x] + val[y] > 0) {
				inp[x] = y;
				inp[y] = x;
				prs.push_back({x, y});
				ans += val[x] + val[y];
				m[rh[i.nd]].pop_front();
			}
		} else {
			if(m.count(fh[i.nd]) == 0) 
				m[fh[i.nd]] = deque <int> ();
			m[fh[i.nd]].push_back(i.nd);
		}
	}
	// dbg(prs);
	// dbg(ans);
	int tmp = ans;

	for(int i = 1; i <= n; i++) {
		if(!pal[i]) continue;
		if(!inp[i]) ans = max(ans, tmp + val[i]);
		else 
			ans = max(ans, tmp - val[inp[i]]);
		// dbg(i, ans);
	}
	cout << ans << '\n';
}