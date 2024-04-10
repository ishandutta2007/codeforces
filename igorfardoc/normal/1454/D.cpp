#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	long long n;
    	cin >> n;
    	int max1 = 1;
    	int maxdel = 1;
    	for(; (long long)maxdel * maxdel < n; maxdel++)
    	{

    	}
    	vector<int> mass(maxdel + 1, 0);
    	for(long long i = 2; i * i <= n; ++i)
    	{
    		while(n % i == 0)
    		{
    			++mass[i];
    			max1 = max(max1, mass[i]);
    			n /= i;
    		}
    	}
    	vector<long long> res(max1, 1);
    	res[res.size() - 1] *= n;
    	for(int i = 2; i < mass.size(); i++)
    	{
    		for(int j = 0; j < mass[i]; j++)
    		{
    			res[res.size() - 1 - j] *= i;
    		}
    	}
    	cout << res.size() << endl;
    	for(int i = 0; i < res.size(); i++)
    	{
    		cout << res[i] << " ";
    	}
    	cout << endl;
    }
}