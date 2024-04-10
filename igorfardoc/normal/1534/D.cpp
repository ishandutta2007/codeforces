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
    int n;
    cin >> n;
    set<pair<int, int> > s;
    cout << "? 1" << endl;
    vector<int> a(n);
    int a1 = 0;
    int a2 = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	if(a[i] != 0)
    	{
    		if(a[i] % 2 == 0)
    		{
    			++a1;
    		}
    		else
    		{
    			++a2;
    		}
    	}
    	if(a[i] == 1)
    	{
    		s.insert({1, i + 1});
    	}
    }
    int ost = 0;
    if(a2 < a1)
    {
    	ost = 1;
    }
    for(int i = 1; i < n; i++)
    {
    	if(a[i] % 2 == ost)
    	{
    		cout << "? " << i + 1 << endl;
    		for(int j = 0; j < n; j++)
	    	{
	    		int b;
	    		cin >> b;
	    		if(b == 1)
	    		{
	    			s.insert({min(i + 1, j + 1), max(i + 1, j + 1)});
	    		}
	    	}
    	}
    	
    }
    cout << "!\n";
    for(auto it = s.begin(); it != s.end(); ++it)
    {
    	cout << (*it).first << ' ' << (*it).second << '\n';
    }
    cout << endl;
}