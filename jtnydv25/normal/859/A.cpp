#include <bits/stdc++.h>
using namespace std;
int main(){
	int k, mx = 0;
	cin >> k;
	for(int i = 1; i <= k; i++){
		int x;
		cin >> x;
		mx = max(mx, x);
	}
	cout << max(0, mx - 25);
}