#include<bits/stdc++.h>
#define MAX 300000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int p[MAX + 1];



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vi dp1(MAX + 1), dp2(MAX + 1); // , 
    p[0] = 1;
    for(int i = 1; i <= MAX; i++)
    {
    	p[i] = (p[i - 1] * 2) % mod;
    }
    for(int i = 0; i <= MAX; i++)
    {
    	if(i < 2)
    	{
    		dp1[i] = 0;
    		dp2[i] = 0;
    		continue;
    	}
    	if(i == 2)
    	{
    		dp1[i] = 0;
    		dp2[i] = 1;
    		continue;
    	}
    	dp1[i] = (dp2[i - 1] + dp1[i - 1]) % mod;
    	///////
    	dp2[i] = ((ll)p[i - 2] + dp1[i - 2] + dp2[i - 2]) % mod;
    	dp2[i] = (dp2[i] + dp1[i - 1]) % mod;
    }
    int n, m;
    cin >> n >> m;
    int res = 0;
    vector<string> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	for(int j = 0; j < m; j++)
    	{
    		sum += a[i][j] == 'o';
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	int prev = -1;
    	for(int j = 0; j <= m; j++)
    	{
    		if(prev != -1 && (j == m || a[i][j] == '*'))
    		{
    			res = (res + ((ll)dp1[j - prev] + dp2[j - prev]) * p[sum - (j - prev)]) % mod;
    			prev = -1;
    		}
    		if(j == m)
    		{
    			continue;
    		}
    		if(a[i][j] == 'o' && prev == -1)
    		{
    			prev = j;
    		}
    	}
    }
    for(int i = 0; i < m; i++)
    {
    	int prev = -1;
    	for(int j = 0; j <= n; j++)
    	{
    		if(prev != -1 && (j == n || a[j][i] == '*'))
    		{
    			res = (res + ((ll)dp1[j - prev] + dp2[j - prev]) * p[sum - (j - prev)]) % mod;
    			prev = -1;
    		}
    		if(j == n)
    		{
    			continue;
    		}
    		if(a[j][i] == 'o' && prev == -1)
    		{
    			prev = j;
    		}
    	}
    }
    cout << res;
}