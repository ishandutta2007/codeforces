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
    	int n, x;
    	cin >> n >> x;
    	vector<int> a(n);
    	int sum = 0;
    	int am = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		sum += a[i];
    		if(a[i] == x)
    		{
    			++am;
    		}
    	}
    	if(am == n)
    	{
    		cout << "0\n";
    		continue;
    	}
    	if(sum == x * n || am > 0)
    	{
    		cout << "1\n";
    		continue;
    	}
		cout << "2\n";
    }
}