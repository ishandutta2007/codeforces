#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T> ostream& print(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return print(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

int n, k, m, pre[34000100], q;


int main() {
	ios_base::sync_with_stdio(false);
	
	pre[33554431] = 1082401;
	pre[16777215] = 5592405;
	pre[8388607] = 178481;
	pre[4194303] = 1398101;
	pre[2097151] = 299593;
	pre[1048575] = 349525;


	cin >> q;
	for(int i =1 ;i <= q; i++) {
		cin >> n;
		int x = 0, cn = n;
		while(cn) cn /= 2, x++;
		int ans = (1 << x) - 1;
		
		if(n == ans) {
			if(pre[n] == 0) {
				for(int b = 1; b < n; b++)
					pre[n] = max(pre[n], __gcd(n & b, n ^ b));
			}
			cout << pre[n] << '\n';
		}
		else cout << ans << '\n';
	}
}