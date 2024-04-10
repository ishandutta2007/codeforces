#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int fact[300000], rfact[300000];

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

int obr(int a)
{
	return bin_pow(a, mod - 2);
}

int c(int n, int k)
{
	if(n < 0 || k < 0 || k > n)
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
    for(int i = 1; i < 300000; i++)
    {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	cout << (ll)fact[2 * n] * rfact[2] % mod << '\n';
    	continue;
    	/*int res = 0;
    	for(int i = n; i < 2 * n; i++)
    	{
    		int here = c(2 * n, i);
    		here = ((ll)here * )
    	}*/
    }
}