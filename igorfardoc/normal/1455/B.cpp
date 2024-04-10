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
    	int x;
    	cin >> x;
    	int res = 0;
    	int now = 1;
    	while(res < x)
    	{
    		res += now++;
    	}
    	if(x != res - 1)
    	{
    		cout << now - 1 << endl;
    	}
    	else
    	{
    		cout << now << endl;
    	}
    }
}