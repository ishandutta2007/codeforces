#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
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
    		cout << (i + 1) % n + 1 << " ";
    	}
    	cout << endl;
    }
}