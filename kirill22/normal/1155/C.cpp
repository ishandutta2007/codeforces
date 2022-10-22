#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < m;i++){
		cin >> b[i];
	}
	int tmp = 0;
	for(int i = 0 ;i < n - 1;i ++){
		tmp = __gcd(tmp,a[i + 1] - a[i]);
	}
	for(int i = 0;i < m;i++){
		if (tmp % b[i] == 0){
			cout << "YES" << endl << a[0] << " " << i + 1;
			return 0;
		}
	}
	cout << "NO";
	
	return 0;
}