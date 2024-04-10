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
    	string s;
    	cin >> s;
    	map<char, int> d;
    	for(int i = 0; i < n; i++)
    	{
    		d[s[i]]++;
    	}
    	for(int i = 0; i < d['b']; i++)
    	{
    		cout << 'b';
    	}
    	for(char i = 'a'; i <= 'z'; i++)
    	{
    		if(i == 'b')
    		{
    			continue;
    		}
    		for(int j = 0; j < d[i]; j++)
    		{
    			cout << i;
    		}
    	}
    	cout << endl;
    }
}