#include<iostream>
#include<cstring>

using namespace std;

typedef long long llint;

const int MAXN = 1005;
const llint INF = 1000000000000LL;

int n, len;
llint cost[MAXN], dp[MAXN] [MAXN], ne[MAXN];
string s;

llint f (char c, int mask) {
	if (c=='k') return 0;
	if (dp[c] [mask]!=-1) return dp[c] [mask];
	llint res=INF;
	for (int i=0; i<10; i++) {
		if (i==0 && ne[c]) continue;
		if ((mask & (1<<i))==0) {
			res=min(res, cost[c]*i + f(c+1, mask | (1<<i))   );
		}
	}
	dp[c] [mask]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		len=s.size();
		for (int j=len-1, pot=1; j>=0; j--, pot*=10) {
			cost[s[j]]+=pot;
		}
		ne[s[0]]=1;
	}
	cout << f('a', 0);
	return 0;
}