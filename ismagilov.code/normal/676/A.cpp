#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int xx, xy;
	int a;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (a == 1){
			xx = i+1;
		}
		if (a == n){
			xy = i+1;
		}
	}
	cout << max(max(abs(1 - xx), abs(1 - xy)), max(abs(n - xx), abs(n - xy)));
}