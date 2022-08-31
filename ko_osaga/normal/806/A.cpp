#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int t;
	cin >> t;
	while(t--){
		lint x, y, p, q;
		cin >> x >> y >> p >> q;
		if(p == 0){
			if(x == 0) cout << 0 << endl;
			else cout << -1 << endl;
			continue;
		}
		if(p == q){
			if(x != y) cout << -1 << endl;
			else cout << 0 << endl;
			continue;
		}
		lint k = max((x + p - 1) / p, (y + q - 1) / q);
		k = max(k, (y - x + q - p - 1) / (q - p));
		cout << q * k - y << endl;
	}
}