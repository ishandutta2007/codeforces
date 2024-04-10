#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define INF 2000000010
#define ST_SIZE 1048600
#define QMAX 400010
#define NMAX 200010

int s[NMAX], g[NMAX];
int leftLow[NMAX], leftUpp[NMAX];
int rightLow[NMAX], rightUpp[NMAX];
int low[NMAX], upp[NMAX];

int main()
{
	int i, n;
	ll lawn;
	
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> s[i] >> g[i];
		
		leftLow[i] = rightLow[i] = s[i];
		leftUpp[i] = rightUpp[i] = s[i] + g[i];
	}
	
	for(i = 2; i <= n; ++i)
	{
		if(leftLow[i] < leftLow[i - 1] - 1)
			leftLow[i] = leftLow[i - 1] - 1;
		
		if(leftUpp[i] > leftUpp[i - 1] + 1)
			leftUpp[i] = leftUpp[i - 1] + 1;
	}
	
	for(i = n - 1; i >= 1; --i)
	{
		if(rightLow[i] < rightLow[i + 1] - 1)
			rightLow[i] = rightLow[i + 1] - 1;
		
		if(rightUpp[i] > rightUpp[i + 1] + 1)
			rightUpp[i] = rightUpp[i + 1] + 1;
	}
	
	for(i = 1; i <= n; ++i)
	{
		low[i] = max(leftLow[i], rightLow[i]);
		upp[i] = min(leftUpp[i], rightUpp[i]);
	}
	
	for(i = 1; i <= n; ++i)
		if(low[i] > upp[i])
			return cout << -1 << '\n', 0;
	
	for(lawn = 0, i = 1; i <= n; ++i)
		lawn += upp[i] - s[i];
	
	cout << lawn << '\n';
	for(i = 1; i <= n; ++i)
		cout << upp[i] << ' ';
	cout << '\n';
	
	return 0;
}