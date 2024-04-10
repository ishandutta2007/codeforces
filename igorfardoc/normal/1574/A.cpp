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
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j <= i; j++)
    		{
    			cout << '(';
    		}
    		for(int j = 0; j <= i; j++)
    		{
    			cout << ')';
    		}
    		for(int j = 0; j < n - i - 1; j++)
    		{
    			cout << "()";
    		}
    		cout << '\n';
    	}
    }
}