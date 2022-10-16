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

const int N = 2018;
int n, k, m;

bool valid(int x, int y) {
	return (x >= 1 && y <= n);
}
void reset(int &x, int &y, int i) {	
	if(i <= n) x = i, y = 1;
	else x = n, y = i + 1 - n;
}

string s[N];
int dp[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "*" + s[i];
	}

	string ans;
	bool ok = true;
	if(k == 0)  {
		dp[1][0] = dp[0][1] = 1;
		ok = 0;
	}

	for(int i = 1; i < 2 * n ; i++) {
		int x, y;
		reset(x, y, i);

		int tmp = 0;
		char c = 'z';

		while(valid(x, y)) {
			if(ok) {
				dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]) + (s[x][y] == 'a');
				tmp = max(tmp, dp[x][y]);
			} else 
				if(dp[x - 1][y] || dp[x][y - 1])
					c = min(c, s[x][y]);

			x--, y++;
		}

		if(ok && i - tmp >= k) {

			for(reset(x, y, i); valid(x, y); x--, y++)
				if(dp[x][y] == tmp)
					dp[x][y] = 1;
				else 
					dp[x][y] = 0;
			
			ok = 0;
			ans = string(i, 'a');

		} else if(!ok) {
			
			for(reset(x, y, i); valid(x, y); x--, y++)
				if(s[x][y] == c && (dp[x - 1][y] || dp[x][y - 1]))
					dp[x][y] = 1;

			ans.push_back(c);
		}

	}

	if(ok) cout << string(2 * n - 1, 'a') << '\n';
 	else cout << ans << '\n';
}