#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int B = 37;
const int MOD = 1e9 + 7;
const int N = 1e6 + 142;


int n, k, m, pwb[N], hsh[N], n0, n1, ans;

string s, t;

char op(char c) {
	if(c == '0') return '1';
	return '0';
}

int getHash(int l, int lg) {
	int r = l + lg - 1;
	int ret = hsh[r] - (l == 0 ? 0 : ((1LL * hsh[l - 1] * pwb[lg]) % MOD));
	if(ret < 0) ret += MOD;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> t;

	pwb[0] = 1;
	for(int i = 1; i <= 1e6 + 10; i++) pwb[i] = (1LL * pwb[i - 1] * B) % MOD;

	hsh[0] = t[0] - 'a' + 1;

	for(int i = 1; i < t.size(); i++)
		hsh[i] = (1LL * hsh[i - 1] * B  + (t[i] - 'a' + 1)) % MOD;

	// dbg_v(hsh, 20);
	// dbg_v(pwb, 20);

	if(s[0] == '1')
		for(int i = 0; i < s.size(); i++) 
			s[i] = op(s[i]);

	for(int i = 0; i < s.size(); i++)
		if(s[i] == '0') n0++;
		else n1++;

	int nn = t.size();
	for(int pas = 1; pas <= t.size(); pas++) {

		if(nn < n0 * pas || (nn == n0 * pas && n1 > 0)) break;
		if((nn - n0 * pas) % n1 != 0) continue;
		
		int pas2 = nn - n0 * pas;
		pas2 /= n1;

		int h0 = getHash(0, pas), h1 = -1;
		int ok = 1, last = 0;

		// dbg(pas);
		// dbg(pas2);
		for(int j = 0; j < s.size() && ok; j++) {
			// dbg(j);
			// dbg(last);
			// dbg(getHash(last, pas));
			if(s[j] == '1') {
				
				if(h1 == -1) h1 = getHash(last, pas2);
				else if(h1 != getHash(last, pas2))
					ok = 0;

				if(h1 == h0) ok = 0;
				
				last += pas2;

			} else {
				
				if(h0 != getHash(last, pas))
					ok = 0;

				last += pas;
			}

		}
		// dbg(h1);
		// dbg(h0);
		ans += ok;
	}	
	cout << ans << '\n';
}