#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

vector<int> init_pi(const string &s)
{
	vector<int> p(s.size());
	for(int i=1; i<s.size(); i++)
	{
		int j = p[i-1];
		while(j && s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) p[i] = j+1;
	}
	return p;
}

int N, M;
string s, t;
int dp[501][501][501];
vector<int> p;
pair<int, int> DP[505][2];

pair<int, int> go(int n, char c)
{
	auto &ret = DP[n][(int)(c-'0')];
	if (ret != make_pair(-1, -1)) return ret;

	int mat = 0;
	while(n && t[n] != c) n = p[n-1];

	if (t[n] == c) // 
	{
		n++;
		if (n == M) n = p[n-1], mat = 1;
	}
	else; // , n == 0

	return ret = {n, mat};
}

int main()
{
	for(int i=0; i<505; i++)
		for(int j=0; j<2; j++)
			DP[i][j] = {-1, -1};
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> M >> s >> t;
	p = init_pi(t);

	// for(int i=0; i<M; i++)
	// 	cout << p[i] << " ";
	// cout << "\n";
	// return 0;

	// int n = 0, sum = 0;
	// for(int i=0; i<N; i++)
	// {
	// 	auto [next,mat] = go(n, s[i]);
	// 	sum += mat;
	// 	n = next;
	// 	cout << next << " ";
	// }
	// cout << "\n";
	// cout << sum << "\n";
	// return 0;

	// dp[k][i][n] : k   i    n     
	for(int k=0; k<=N-M+1; k++)
	{
		for(int n=0; n<M; n++)
		{
			if (k == 0) dp[k][N][n] = 0;
			else dp[k][N][n] = INF;
		}

		for(int i=N-1; i>=0; i--)
		{
			for(int n=0; n<M; n++)
			{
				int &ret = dp[k][i][n];
				ret = INF;
				
				if (1) //  
				{
					auto [next,mat] = go(n, s[i]);
					if (k-mat >= 0)
						ret = min(ret, dp[k-mat][i+1][next]);
				}

				if (2) // 
				{
					auto [next,mat] = go(n, (s[i] == '0' ? '1' : '0'));
					if (k-mat >= 0)
						ret = min(ret, dp[k-mat][i+1][next] + 1);
				}
			}
		}
	}
	for(int k=0; k<=N-M+1; k++)
	{
		int res = dp[k][0][0];
		if (res == INF) res = -1;
		cout << res << " ";
	}
	cout << "\n";
	return 0;
}