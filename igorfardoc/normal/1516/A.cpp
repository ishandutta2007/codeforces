#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
    	if(k == 0)
    	{
    		break;
    	}
    	int minus = min(a[i], k);
    	a[i] -= minus;
    	k -= minus;
    	a[n - 1] += minus;
    }
    for(int i = 0; i < n; i++)
    {
    	cout << a[i] << ' ';
    }
    cout << '\n';
}
}