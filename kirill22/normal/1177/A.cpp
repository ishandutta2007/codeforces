#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int size = 1, tmp = 9, min = 1;
	while(true){
		if(size * tmp < n){
			n -= size * tmp;
			size++;
			tmp *= 10;
			min *= 10;
		}
		else{
			int ans = min + (n - 1) / size;
			n = (n - 1) % size;
			string s = to_string(ans);
			cout << s[n];
			return 0;
		}
	}
}