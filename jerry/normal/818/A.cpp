#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, w;

int main()
{
	cin >> n >> k;
	w = n/2/(k+1)*(k+1);
	cout << w/(k+1) << ' ' << w/(k+1)*k << ' ' << n-w << endl;
	return 0;
}