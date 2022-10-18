#include <bits/stdc++.h>
using namespace std;

main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (b > 0){
		for (int i = 0; i < b; i++){
			if (a == n){
				a = 1;
			}
			else{
				a++;
			}
		}
	}
	else{
		for (int i = 0; i < b * -1; i++){
			//cout << a << endl;
			if (a == 1){
				a = n;
			}
			else{
				a--;
			}
		}
	}
	cout << a;
	return 0;
}