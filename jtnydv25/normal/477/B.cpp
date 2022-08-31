#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;	
	cout << (6 * (n - 1) + 5) * k << endl;
	for(int i = 0; i < n; i++){
		int x = k * (6 * i + 1);
		cout << x << " " << x + k << " " << x + 2 * k <<" " << x + 4* k << endl;
	}
}