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

const int N = 1040;
int n, op[N];
char mn = 'z';
string s;

void solve(string s) {
	if(s.size() <= 1) return;

	char mn = 'z', first_pos = s.size();
	for(int i = 0; i < s.size(); i++)
		if(s[i] < mn) {
			mn = s[i];
			first_pos = i;
		}

	solve(s.substr(0, first_pos));

	int is_near = 1;
	for(int i = first_pos; i < s.size(); i++)
		if(s[i] == mn) {
			if(i + 1 != s.size() && s[i + 1] != mn)
				op[i] = 1;
		} else {
			if(i + 1 == s.size() || s[i + 1] == mn)
				op[i] = 1;
		}
}

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> s;

	solve(s);
	op[s.size() - 1] = 1 - op[s.size() - 1];

	for(int i = 0; i < s.size(); i++) 
		cout << op[i] << ' ';
}