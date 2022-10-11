#include <bits/stdc++.h>
using namespace std;
int n, a, x, b, y;
int main(){
	cin >> n >> a >> x >> b >> y;
	if (a == b){
		cout << "YES";
		return 0;
	}
	while (a != x && b != y){
		a = a % n + 1;
		if (b == 1){
			b = n + 1;
		}
		b--;
		if (a == b){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}