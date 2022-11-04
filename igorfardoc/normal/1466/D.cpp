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
    	vector<int> w(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> w[i];
    	}
    	vector<int> a(n, 0);
    	for(int i = 0; i < n - 1; i++)
    	{
    		int x, y;
    		cin >> x >> y;
    		a[x - 1]++;
    		a[y - 1]++;
    	}
    	vector<pair<int, int> > mass(n);
    	ll now = 0;
    	for(int i = 0; i < n; i++)
    	{
    		now += w[i];
    		mass[i] = {-w[i], a[i] - 1};
    	}
    	sort(mass.begin(), mass.end());
    	cout << now << ' ';
    	int now1 = 0;
    	for(int i = 0; i < n - 2; i++)
    	{
    		while(now1 < n && mass[now1].second == 0)
    		{
    			now1++;
    		}
    		if(now1 < n)
    		{
    			now += -(mass[now1].first);
    			mass[now1].second--;
    		}
    		cout << now << ' ';
    	}
    	cout << '\n';
    }
}