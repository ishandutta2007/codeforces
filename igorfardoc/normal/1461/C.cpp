#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;



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
    	int n, m;
    	cin >> n >> m;
    	vector<int> a(n);
    	int last = -1;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		--a[i];
    		if(a[i] != i)
    		{
    			last = i;
    		}
    	}
    	ld ver = 1;
    	if(last == -1)
    	{
    		ver = 0;
    	}
    	for(int i = 0; i < m; i++)
    	{
    		int r;
    		ld p;
    		cin >> r >> p;
    		--r;
    		if(r >= last)
    		{
    			ver *= (1 - p);
    		}
    	}
    	cout << fixed << setprecision(20) << 1 - ver << '\n';
    }
}