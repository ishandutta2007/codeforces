#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int m = 0;
	while(true){
		if(m * 2 - 1 <= n - 1){
			m++;
		}
		else{
			break;
		}
	}
	cout << m << endl;
	int x = 1, y = 1;
	for(int i = 0;i < n;i++){
		cout << x << " " << y << endl;
		if(x < m){
			x++;
		}
		else{
			y++;
		}
	}
}