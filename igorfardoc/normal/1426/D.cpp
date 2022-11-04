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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    ll now = 0;
    set<ll> s;
    s.insert(0);
    int am = 0;
    for(int i = 0; i < n; i++)
    {
    	now += a[i];
    	if(s.find(now) != s.end())
    	{
    		++am;
    		s.clear();
    		s.insert(0);
    		s.insert(a[i]);
    		now = a[i];
    	}
    	else
    	{
    		s.insert(now);
    	}
    }
    cout << am;
}