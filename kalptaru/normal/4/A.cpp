#include <bits/stdc++.h>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
    int w;
    cin >> w;

    if (w%2 == 0 && w>2)
    {
    	cout << "YES";
    }
	else
	{
		cout << "NO";
	} 
	// cout << "Hello Mr.";




return 0;
}