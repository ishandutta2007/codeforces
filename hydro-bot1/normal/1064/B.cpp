// Hydro submission #6185264c9a242033b6e192ba@1636116092416
#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << (1<<__builtin_popcount(n)) << endl;
	}
	return 0;
}