#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int bin_pow(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	int res = bin_pow(a, b / 2);
	res = ((ll)res * res) % mod;
	if(b & 1)
	{
		res = ((ll)res * a) % mod;
	}
	return res;
}
int obr(int a)
{
	return bin_pow(a, mod - 2);
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		cin >> a[i][j];
    	}
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
    	vector<int> b;
    	for(int j = 0; j < n; j++)
    	{
    		b.push_back(a[j][i]);
    	}
    	sort(b.begin(), b.end());
    	int am = 0;
    	int mn = 1;
    	for(int j = 0; j < b.size(); j++)
    	{
    		if(j != (int)b.size() - 1 && b[j + 1] == b[j])
    		{
    			++am;
    			continue;
    		}
    		++am;
    		int n1 = (int)b.size() - j - 1 + am;
    		int k1 = min(n - b[j] + 1, n1);
    		int now = 1;
    		int adding = 0;
    		for(int _ = 0; _ < am; _++)
    		{
    			if(now == 0)
    			{
    				break;
    			}
    			int res = now;
    			res = ((ll)k1 * res) % mod;
    			res = ((ll)res * obr(n1)) % mod;
    			adding = ((ll)adding + res) % mod;
    			now = ((ll)now * (n1 - k1)) % mod;
    			now = ((ll)now * obr(n1)) % mod;
    			--n1;
    		}
    		int resulthere = ((ll)mn * adding) % mod;
    		ans = ((ll)ans + resulthere) % mod;
    		mn = ((ll)mn - resulthere + mod) % mod;
    		am = 0;
    	}
    	//cout << ans << endl;
    }
    cout << ans;
}