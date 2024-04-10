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
int n, cc[N], nxt[N], nxt2[N], val[N], nrc;

vector <int> v[N], c[N], ans[5];

string s;

void query_1(int start) {
	vector <int> q;
	for(int i = start; i + 1 <= n; i += 2)
		q.push_back(i), q.push_back(i + 1);

	cout << "Q " << q.size() / 2 << ' ';

	if(q.size() == 0) return;

	for(auto i : q) cout << i << ' ';
	cout << endl;

	cin >> s;
	for(int i = start, j = 0; i + 1 <= n; i += 2, j++)
		if(s[j] == '1')
			nxt[i] = 1;
}

void query_2(int start) {
	vector <int> q;
	for(int i = start; i + 2 < nrc; i += 4)
		q.push_back(c[i][0]), q.push_back(c[i + 2][0]);

	if(q.size() == 0) return;

	cout << "Q " << q.size() / 2 << ' ';

	for(auto i : q) cout << i << ' ';
	cout << endl;

	cin >> s;
	for(int i = start, j = 0; i + 2 < nrc; i += 4)
		if(s[j++] == '0')
			nxt2[i + 2] = 1;
}

void solve() {
	cin >> n;

	query_1(1);
	query_1(2);

	for(int i = 1; i <= n; i++) {
		c[nrc].push_back(i);
		while(nxt[i]) i++, c[nrc].push_back(i);
		nrc++;
	}

	query_2(0);
	query_2(1);
	query_2(2);
	query_2(3);

	val[0] = 0;
	val[1] = 1;
	for(auto i : c[0]) ans[0].push_back(i);//ans[0] += c[0].size();
	for(auto i : c[1]) ans[1].push_back(i);//ans[1] += c[1].size();

	for(int i = 2; i < nrc; i++) {
		if(nxt2[i] == 0)
			val[i] = val[i - 2];
		else 
			val[i] = 3 - val[i - 1] - val[i - 2];
		for(auto ii : c[i]) ans[val[i]].push_back(ii);//ans[val[i]] += c[i].size();
	}

	cout << "A ";
	for(int i = 1; i <= 3; i++)
		cout << ans[i - 1].size() << ' ';
	
	cout << endl;
	for(int i = 0; i < 3; i++) {
		for(auto j : ans[i]) 
			cout << j << ' ';
		cout << endl;
	}

	for(int i = 0; i <= nrc; i++) 
		c[i].clear();

	nrc = 0;
	memset(nxt, 0, sizeof nxt);
	memset(nxt2, 0, sizeof nxt2);
	ans[0].clear();
	ans[1].clear();
	ans[2].clear();
	// memset(ans, 0, sizeof ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--)
		solve();
}