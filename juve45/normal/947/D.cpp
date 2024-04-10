#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, a, b, c, d, lt[DMAX], ls[DMAX], cs[DMAX], ct[DMAX], q;

string s, t;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


void pre() {
	lt[0] = ct[0] = (t[0] == 'A');
	for(int i = 1; i < t.size(); i++) {
		//ct, lt;
		ct[i] = ct[i - 1] + (t[i] == 'A');
		lt[i] = (t[i] == 'A' ? lt[i - 1] + 1 : 0);
	}


	ls[0] = cs[0] = (s[0] == 'A');
	for(int i = 1; i < s.size(); i++) {
		//cs, ls;
		cs[i] = cs[i - 1] + (s[i] == 'A');
		ls[i] = (s[i] == 'A' ? ls[i - 1] + 1 : 0);
	}
}

int solve() {
	//s[a..b] -> t[c..d]
	cin >> a >> b >> c >> d;
	a--, b--, c--, d--;
	int szs = b - a + 1;
	int szt = d - c + 1;
	int lsts = min(szs, ls[b]);
	int lstt = min(szt, lt[d]);
	
	
	int nrs = cs[b];
	int nrt = ct[d];
	if(a > 0) nrs -= cs[a - 1];
	if(c > 0) nrt -= ct[c - 1];

	int bs = szs - nrs;
	int bt = szt - nrt;
	
	if(lsts < lstt) 
		return 0;
	if(lsts == lstt && bs == 0 && bt != 0)
		return 0; 
	
	if(lsts > lstt && (lsts - lstt) % 3 != 0) 
		bs += 2;



	if(bs > bt)
		return 0;

	if(bs % 2 != bt % 2)
		return 0;
	
	return 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	pre();
	dbg_v(ls, 13);
	dbg_v(lt, 13);
	dbg_v(cs, 13);
	dbg_v(ct, 13);

	cin >> q;

	for(int i = 1; i <= q; i++) 
		cout << solve();
}