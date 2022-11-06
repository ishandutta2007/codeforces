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
	int p,v,t,total;
	int output = 0;
	cin >> total;
	for (int remd = total; remd > 0 ; remd = remd-1)
	{
		cin >> p;
		cin >> v;
		cin >> t;
		if (p+v+t >= 2)
		{
			output = output+1;
		}
	}
	cout << output;

}