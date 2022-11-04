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
    	vector<int> a(2 * n);
    	for(int i = 0; i < 2 * n; i++)
    	{
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	for(int i = 0; i < n; i++)
    	{
    		cout << a[i] << ' ' << a[i + n] << ' ';
    	}
    	cout << '\n';
    }
}