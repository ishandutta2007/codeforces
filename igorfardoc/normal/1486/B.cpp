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
    	vector<int> x(n), y(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> x[i] >> y[i];
    	}
    	sort(x.begin(), x.end());
    	sort(y.begin(), y.end());
    	if(n % 2 == 1)
    	{
    		cout << "1\n";
    		continue;
    	}
    	else
    	{
    		cout << ((long long)x[n / 2] - x[n / 2 - 1] + 1) * ((long long)y[n / 2] - y[n / 2 - 1] + 1) << '\n';
    	}
    }
}