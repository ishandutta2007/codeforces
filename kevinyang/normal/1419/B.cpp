#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		int count = 0;
		int cur = 1;
		int total = 0;
		while(total+cur*(cur+1)/2<=x){
			count++;
			total+=cur*(cur+1)/2;
			cur*=2; cur++;
		}
		cout << count << "\n";
	}
	return 0;
}