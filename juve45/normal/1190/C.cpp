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
int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s;

	int pre = 0, suf = 0;
	while(pre < s.size() && s[0] == s[pre]) pre++;
	while(suf < s.size() && s.back() == s[s.size() - suf - 1]) suf++;

	dbg(pre, suf, k);
	if(pre + k >= n || suf + k >= n) return cout << "tokitsukaze\n", 0;
	if(s[0] == s.back() && pre + suf + k >= n) return cout << "tokitsukaze\n", 0;

	if(2 * k < n)
		return cout << "once again\n", 0;

	if(pre >= k || suf >= k)
		return cout << "once again\n", 0;

	if(s[0] == s.back()) {
		for(int i = 0; i + k + 1 < s.size(); i++)
			if(s[i] != s[i + k + 1])
				return cout << "once again\n", 0;

	} else {
		if(min(suf, pre) + k + 1 < n)
			return cout << "once again\n", 0;
	}


	// if(n <= k + 2) 
	// if(min(pre, suf) + 2 * k >= n)
		return cout << "quailty\n", 0;


}