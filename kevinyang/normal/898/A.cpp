#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int v = n%10;
	if(v>=5)n+=10-v;
	else n-=v;
	cout << n << "\n";
	return 0;
}