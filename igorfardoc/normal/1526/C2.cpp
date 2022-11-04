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
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    ll now = 0;
    multiset<ll> s;
    for(int i = 0; i < n; i++)
    {
    	now += a[i];
    	s.insert(a[i]);
    	while(now < 0)
    	{
    		now -= *s.begin();
    		s.erase(s.begin());
    	}
    }
    cout << s.size();
}