#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, a, b;
		cin >> n >> a >> b;
		if (a>b) swap(a, b);
		cout << b-(a+b-n)+1 << endl;
	}
	return 0;
}