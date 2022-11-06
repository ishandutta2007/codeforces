#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
    ll a,n,m,d,e;
    cin >> n>>m>>a;
    ll b = n%a;
    ll c = m%a;
    if (b == 0)
    {
    	d = n/a;
    }
	else
	{
	 d = n/a + 1;
	}


	    if (c == 0)
    {
    	e = m/a;
    }
	else
	{
e = m/a + 1;
	}
	cout << d*e; 


return 0;
}