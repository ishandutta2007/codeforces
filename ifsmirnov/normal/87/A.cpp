#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

ll a, b;
ll ca, cb;
bool sw = false;

int main()
{
	cin >> a >> b;
	if (a < b) swap(a, b), sw = 1;
	
	ll c = 0;
	forn(i, b)
	{
		c += a;
		ll md = c%b;
		if (!md) md += b;
		ca += md;
		cb += a-md;
	}
	//cout << ca << " " << cb << endl;
	if (ca == cb) cout << "Equal";
	else if ((ca>cb)^sw) cout << "Dasha";
	else cout << "Masha";
};