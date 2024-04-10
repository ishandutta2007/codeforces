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
    	bool ok = true;
    	for(int i = 0; i < n; i++)
    	{
    		int a;
    		cin >> a;
    		ok = ok & (a >= 0);
    	}
    	if(!ok)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n101\n";
    	for(int i = 0; i <= 100; i++)
    	{
    		cout << i << ' ';
    	}
    	cout << '\n';
    }
}