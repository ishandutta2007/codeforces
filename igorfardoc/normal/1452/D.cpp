#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int bin_pow(int a, int b)
{
	a %= mod;
	int res = 1;
	while(b)
	{
		if(b % 2 == 0)
		{
			b /= 2;
			a = ((long long)a * a) % mod;
		}
		else
		{
			--b;
			res = ((long long)res * a) % mod;
		}
	}
	return res;
}

pair<int, int> sum(int a, int a1, int b, int b1)
{
	if(a1 > b1)
	{
		return {(a + b * (1ll << (a1 - b1))) % mod, a1};
	}
	else
	{
		return {(b + a * (1ll << (b1 - a1))) % mod, b1};
	}
}



void res(int a, int b)
{
	a = a % mod;
	int bnew = 1;
	for(int i = 0; i < b; i++)
	{
		bnew = ((long long)bnew * 2) % mod;
	}
	cout << (((long long)a * bin_pow(bnew, mod - 2))) % mod;
}


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    int a = 1;
    int a1 = 1;
    int b = 0;
    int b1 = 0;
    for(int i = 0; i < n; i++)
    {
    	if(i % 2 == 0)
    	{
    		if(i == n - 1)
    		{
    			res(a, a1);
    			break;
    		}
    		auto p = sum(a, a1, b, b1);
    		b = p.first;
    		b1 = p.second + 1;
    		++a1;
    	}
    	else
    	{
    		if(i == n - 1)
    		{
    			res(b, b1);
    			break;
    		}
    		auto p = sum(a, a1, b, b1);
    		a = p.first;
    		a1 = p.second + 1;
    		++b1;
    	}
    }
}