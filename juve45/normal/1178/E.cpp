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
int n, f[6];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;

	int nr_grupe = s.size() / 4;

	string l;

	for(int i = 0; i < s.size(); i+=2) {
		if(i == nr_grupe * 2) {
			if(s.size() % 4)
				cout << s[i];
			break;
		}
		f[0] = f[1] = f[2] = 0;

		f[s[i] - 'a']++;
		f[s[i + 1] - 'a']++;
		f[s[s.size() - i - 1] - 'a']++;
		f[s[s.size() - i - 2] - 'a']++;
		for(int j = 0; j < 3; j++) {
			if(f[j] >= 2)  {
				cout << char('a'+j);
				l += 'a' + j;
				break;
			}
		}

	}

	reverse(l.begin(), l.end());
	cout << l;
}