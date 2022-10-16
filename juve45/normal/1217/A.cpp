#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define min(a,b) ((a<b) ? (a) : (b))
#define max(a,b) ((a>b) ? (a) : (b))
#define pb push_back
#define mp make_pair
#define ll long long
 
using namespace std;
 
int t, st, in, xp, dif;
 
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> st >> in >> xp;
		dif = st + xp - in;
		if (dif <= 0)
			cout << 0 << '\n';
		else
			cout << min(xp+1,dif / 2 + dif % 2) << '\n';
	}
	return 0;
}