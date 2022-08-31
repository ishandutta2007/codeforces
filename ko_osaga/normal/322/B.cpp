#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int main(){
	int r, g, b;
	cin >> r >> g >> b;
	int ret = 0;
	for(int i=0; i<=min({10, r, g, b}); i++){
		ret = max(ret, (r-i) / 3 + (g-i) / 3 + (b-i) / 3 + i);
	}
	cout << ret;
}