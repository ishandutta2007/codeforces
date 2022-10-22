#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	//4,8,15,16,23,42
	vector<int> b(6, 0);
	for(int i = 0;i < n;i++){
		if(a[i] == 4){
			b[0]++;
		}
		if(a[i] == 8 && b[0] > 0){
			b[1]++;
			b[0]--;
		}
		if(a[i] == 15 && b[1] > 0){
			b[2]++;
			b[1]--;
		}
		if(a[i] ==16 && b[2] > 0){
			b[3]++;
			b[2]--;
		}
		if(a[i] == 23 && b[3] > 0){
			b[4]++;
			b[3]--;
		}
		if(a[i] == 42 && b[4] > 0){
			b[5]++;
			b[4]--;
		}
	}
	cout << n - b[5] * 6;
}