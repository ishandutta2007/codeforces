#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

const int D = 510;
const int S = 5010;

bool dp[S][D];
pair<pii, int> prv[S][D];
queue<pii> q;

string reconstruct(int s, int r) {
	if(prv[s][r].se == -1) return "";
	
	return reconstruct(prv[s][r].fi.fi, prv[s][r].fi.se) + char(prv[s][r].se + '0');
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int d, s;
	
	cin >> d >> s;
	
	memset(dp, 0, sizeof dp);
	memset(prv, -1, sizeof prv);
	
	q.push({0, 0});
	dp[0][0] = true;
	
	while(!q.empty()) {
		int sd = q.front().fi;
		int r = q.front().se;
		q.pop();
		
		for(int dig = 0; dig < 10; ++dig) {
			int newr = (r * 10 + dig) % d;
			
			if(sd + dig > s) continue;
			
			if(!dp[sd + dig][newr]) {
				dp[sd + dig][newr] = true;
				prv[sd + dig][newr] = {{sd, r}, dig};
				q.push({sd + dig, newr});
			}
		}
	}
	
	if(!dp[s][0]) cout << -1 << '\n';
	else cout << reconstruct(s, 0) << '\n';
	
	return 0;
}