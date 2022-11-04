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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	vector<int> b(101, 0);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		b[a[i]]++;
    	}
    	for(int i = 0; i <= 100; i++)
    	{
    		if(b[i] > 0)
    		{
    			cout << i << ' ';
    		}
    		--b[i];
    	}
    	for(int i = 0; i <= 100; i++)
    	{
    		for(int j = 0; j < b[i]; j++)
    		{
    			cout << i << ' ';
    		}	
    	}
    	cout << '\n';
    }
}