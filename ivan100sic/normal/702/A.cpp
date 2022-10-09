#include "bits/stdc++.h"
using namespace std;

int main(){
	int m = 1, r = 0, n, x, y = 2e9;
	cin >> n;
	while (n--){
		cin >> x;
		if (x > y){
			r++;
		} else {
			r = 1;
		}
		y = x;
		m = max(m, r);
	}
	cout << m;
	return 0;
}