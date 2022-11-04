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
    	cout << 3 * n << '\n';
    	for(int i = 0; i < n; i += 2)
    	{
    		cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
    		cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
    		cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
    		cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
    		cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
    		cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
    	}
    }
}