#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x;
string s;


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e << ' ';
	return out;
}

int ok[5010][5010];

void go(bool rev) {
	for(int i = 0; i < s.size(); i++) {
		
		int nrs = 0, nrp = 0, nrpd = 0;

		for(int j = i; j < s.size(); j++) {
			
			if(s[j] == '(') nrp++;
			if(s[j] == ')') nrp--;
			if(s[j] == '?') nrs++;

			if(nrp < 0) {
				if(nrs > 0)
					nrs--, nrp++;
				else break;
			}
			if((j - i + 1) % 2 == 0) {
				if(nrp == 0 || nrp <= nrs){
					// dbg(i);
					// dbg(j);
					if(rev) ok[s.size() - j - 1][s.size() - i - 1]++;
					else ok[i][j]++;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s;
	int ans = 0;

	go(0);
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') s[i] = ')';
		else if(s[i] == ')') s[i] = '(';
	}
	// dbg(s);

	go(1);
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < s.size(); j++) {
			// cout << ok[i][j] << ' ';
			if(ok[i][j] == 2) ans++;
		}
		// cout << '\n';
	}
	cout << ans << '\n';
}