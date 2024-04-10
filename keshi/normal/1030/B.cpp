#include <bits/stdc++.h>
using namespace std;
int n, d, t, x, y;
int main(){
	cin >> n >> d;
	cin >> t;
	while(t--){
		cin >> x >> y;
		if(x >= y - d && y >= x - d && x >= d - y && d - (n - y)<= n - x){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}