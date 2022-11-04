#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	vector<int> res;
    	for(int i = 0; i < k - 3; i++)
    	{
    		res.push_back(1);
    	}
    	n = n - k + 3;
    	if(n % 2 == 1)
    	{
    		res.push_back(1);
    		res.push_back(n / 2);
    		res.push_back(n / 2);
    	}
    	else if(n % 4 == 0)
    	{
    		res.push_back(n / 4);
    		res.push_back(n / 4);
    		res.push_back(n / 2);
    	}
    	else
    	{
    		res.push_back(2);
    		res.push_back((n - 2) / 2);
    		res.push_back((n - 2) / 2);
    	}
    	for(int i = 0; i < k; i++)
    	{
    		cout << res[i] << ' ';
    	}
    	cout << '\n';
    }
}