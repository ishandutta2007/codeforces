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
    	vector<int> a(3);
    	string s;
    	cin >> s;
    	for(int i = 0; i < s.size(); i++)
    	{
    		a[s[i] - 'A']++;
    	}
    	if(a[1] == a[0] + a[2])
    	{
    		cout << "YES\n";
    	}
    	else
    	{
    		cout << "NO\n";
    	}
    }
}