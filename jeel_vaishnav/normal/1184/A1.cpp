#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int r;
	cin >> r;
	if(r % 2 == 0 || r <= 4)
		cout << "NO";
	else
		cout << 1 << " " << (r - 3) / 2;
	return 0;
}