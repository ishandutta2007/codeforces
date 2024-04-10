#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fact[1000000], rfact[1000000];
const int mod = 998244353;

int bin_pow(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a;
	}
	int res = bin_pow(a, b / 2);
	res = ((ll)res * res) % mod;
	if(b & 1)
	{
		res = ((ll)res * a) % mod;
	}
	return res;
}

int c(int n, int k)
{
	if(n < 0 || k > n || k < 0)
	{
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % mod;
	res = ((ll)res * rfact[n - k]) % mod;
	return res;
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
    fact[0] = 1;
    for(int i = 1; i < 1000000; i++)
    {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = bin_pow(fact[i], mod - 2);
    }
    rfact[0] = rfact[1];
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	int a1 = 0;
    	int a2 = 0;
    	bool not1 = false;
    	for(int i = 0; i < n; i++)
    	{
    		if(s[i] == '0')
    		{
    			++a1;
    			not1 = false;
    			continue;
    		}
    		if(!not1 && i != n - 1 && s[i + 1] == '1')
    		{
    			not1 = true;
    			a2++;
    		}
    		else
    		{
    			not1 = false;
    		}
    	}
    	cout << c(a1 + a2, a2) << '\n';
    }
}