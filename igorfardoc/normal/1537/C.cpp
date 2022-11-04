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
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	int id = -1;
    	int delta = 1000000000;
    	for(int i = 0; i < n - 1; i++)
    	{
    		if(a[i + 1] - a[i] < delta)
    		{
    			delta = a[i + 1] - a[i];
    			id = i;
    		}
    	}
    	/*if(a[1] - a[0] == delta)
    	{
    		id = 0;
    	}
    	if(a[n - 1] - a[n - 2] == delta)
    	{
    		id = n - 2;
    	}*/
    	cout << a[id] << ' ';
    	for(int i = id + 2; i < n; i++)
    	{
    		cout << a[i] << ' ';
    	}
    	for(int i = 0; i < id; i++)
    	{
    		cout << a[i] << ' ';
    	}
    	cout << a[id + 1] << '\n';
    }
}