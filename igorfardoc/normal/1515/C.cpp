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
    	int n, m, x;
    	cin >> n >> m >> x;
    	multiset<pair<int, int>> s;
    	for(int i = 0; i < m; i++)
    	{
    		s.insert({0, i});
    	}
    	cout << "YES\n";
    	for(int i = 0; i < n; i++)
    	{
    		int b;
    		cin >> b;
    		auto it = s.begin();
    		auto p = *it;
    		s.erase(it);
    		cout << p.second + 1 << ' ';
    		p.first += b;
    		s.insert(p);
    	}
    	cout << '\n';
    }
}