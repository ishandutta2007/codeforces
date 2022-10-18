#include <iostream>
#define int long long
using namespace std;

main() {
	int n, h, k;
	cin >> n >> h >> k;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int tek = 0;
	int tek1 = 0;
	int i = 0;
	while(tek < n){
		while(tek < n && tek1 + a[tek] <= h){
			tek1 += a[tek];
			tek++;
		}
		tek1 -= min(k, tek1);
		i++;
		i += tek1 / k;
		tek1 = tek1 % k;
		//cout << i << ' ' << tek << ' ' << tek1 << endl;
	}
	//cout << tek1;
	i += (tek1 + k - 1) / k;
	cout << i;
}