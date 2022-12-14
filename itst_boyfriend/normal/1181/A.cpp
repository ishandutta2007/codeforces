#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	#endif
	#define int long long
	int X , Y , Z;
	cin >> X >> Y >> Z;
	int sum = X / Z + Y / Z , p = X % Z , q = Y % Z;
	if(p + q >= Z)
		cout << sum + 1 << ' ' << min(Z - p , Z - q);
	else cout << sum << ' ' << 0;
	return 0;
}