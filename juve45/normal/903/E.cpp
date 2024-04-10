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

typedef unsigned long long ull;

const int N = 5005;
const int B = 29;
int n, m;
ull pwb[N];
unordered_set <ull> hs[N];
string s[N];

void pre() {
	pwb[0] = 1;
	for(int i = 1; i < N; i++) pwb[i] = pwb[i - 1] * B;
}

ull get_h(string & s) {
	ull ret = 0;
	for(int i = 0;i < s.size(); i++) 
		ret += pwb[i] * (s[i] - 'a' + 1);
	return ret;
}

bool check(ull hash) {
	for(int k = 1; k < n; k++) 
		if(!hs[k].count(hash))
			return 0;
	return 1;
}

bool ss(string s) {
	int f[256];
	memset(f, 0, sizeof f);
	for(auto i : s) {
		if(f[i] > 0) return 1;
		f[i]++;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);	

	pre();
	cin >> n >> m;
	for(int k = 1; k <= n; k++)
		cin >> s[k];
	
	if(n == 1) {
		swap(s[1][0], s[1][1]);
		cout << s[1];
		return 0;
	}

	vector <int> pos;
	int ii = -1;
	for(int el = 2; el <= n; el++)
		if(s[1] != s[el])
			ii = el;
	if(ii == -1) {
		pos.push_back(0);
		pos.push_back(1);
	} else {
		for(int i = 0; i < s[1].size(); i++) {
			// dbg(s[2][i], s[1][i]);
			if(s[ii][i] != s[1][i])
				pos.push_back(i);
		}
	}

	if(pos.size() > 4) {
		cout << "-1\n";
		return 0;
	}
	// dbg(pos);

	bool ok = ss(s[1]);
	dbg(ok);

	for(int k = 1; k <= n; k++) {	
		ull hash = get_h(s[k]);

		vector <int> pos1;
		if(s[1] == s[k]) pos1 = pos;
		else {
			for(int i = 0; i < s[1].size(); i++)
				if(s[k][i] != s[1][i])
					pos1.push_back(i);
			if(pos1.size() > 4) {
				cout << "-1\n";
				return 0;
			}
		}
		// dbg(k);
		// dbg(pos1);
		for(auto i : pos1) 
			for(int j = 0; j < s[1].size(); j++) {
				if(j == i and !ok) continue;
				ull h2 = hash;
				h2 -= pwb[i] * (s[k][i] - 'a' + 1) - pwb[j] * (s[k][i] - 'a' + 1);
				h2 -= pwb[j] * (s[k][j] - 'a' + 1) - pwb[i] * (s[k][j] - 'a' + 1);
				hs[k].insert(h2);
			}
	}
	
	int k = n;
	ull hash = get_h(s[k]);
	for(int i = 0; i < pos.size(); i++)
		for(int j = 0; j < s[1].size(); j++) {
			if(j == pos[i] and !ok) continue;
			ull h2 = hash;
			h2 -= pwb[pos[i]] * (s[k][pos[i]] - 'a' + 1) - pwb[j] * (s[k][pos[i]] - 'a' + 1);
			h2 -= pwb[j] * (s[k][j] - 'a' + 1) - pwb[pos[i]] * (s[k][j] - 'a' + 1);
			if(check(h2)) {
				swap(s[n][pos[i]], s[n][j]);
				cout << s[n] << endl;
				return 0;
			}
		}
	cout << "-1\n";
}