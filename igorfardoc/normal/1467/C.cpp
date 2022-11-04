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
    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<int> > a(3);
    ll sum = 0;
    ll minus = 1000000000000000ll;
    for(int i = 0; i < 3; i++)
    {
    	a[i].resize(n[i]);
    	ll sum1 = 0;
    	for(int j = 0; j < n[i]; j++)
    	{
    		cin >> a[i][j];
    		sum += a[i][j];
    		sum1 += a[i][j];
    	}
    	sort(a[i].begin(), a[i].end());
    	minus = min(minus, sum1);
    }
    for(int i = 0; i < 3; i++)
    {
    	for(int j = i + 1; j < 3; j++)
    	{
    		minus = min(minus, (ll)a[i][0] + a[j][0]);
    	}
    }
    cout << sum - minus - minus;
}