#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
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



int fact[2000001];
int rfact[2000001];

int c(int n, int k)
{
	if(n < 0 || k < 0)
	{
		return 0;
	}
	if(k > n)
	{
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % mod;
	res = ((ll)res * rfact[n - k]) % mod;
	return res;
}

void precalc()
{
	fact[0] = 1;
	rfact[0] = 1;
	for(int i = 1; i <= 2000000; ++i)
	{
		fact[i] = ((ll)i * fact[i - 1]) % mod;
		rfact[i] = obr(fact[i]);
	}
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
    precalc();
    int n;
    cin >> n;
    int start = 0;
    if(n % 2 == 1)
    {
    	start = 1;
    }
    int ans = 0;
    for(int i = start; i < n; i += 2)
    {
    	int res = ((ll)c(n - 1 - (i - 1), i) + c(n - 3 - (i - 2), i - 1)) % mod;
    	res = ((ll)res * fact[n - i]) % mod;
    	res = ((ll)res * 2) % mod;
    	ans = ((ll)ans + res) % mod;
    }
    cout << ans;
}