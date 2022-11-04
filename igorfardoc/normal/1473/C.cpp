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
    	vector<int> ans(k);
    	int a1 = n - k + 1;
    	int a2 = k - a1;
    	for(int i = 0; i < a2; i++)
    	{
    		ans[i] = i + 1;
    	}
    	for(int i = 0; i < a1; i++)
    	{
    		ans[k - i - 1] = a2 + i + 1;
    	}
    	for(int i = 0; i < k; i++)
    	{
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    }
}