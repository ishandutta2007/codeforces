#include <bits/stdc++.h>
    
using namespace std;
int main() {
	vector<int> res;
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i = 1; i <= 1000000000; i++){
		int l = 0;
		int r = n-1;
		if (a[lower_bound(a, a+n, i) - a] != i && (m >= i)){
			res.push_back(i);
			m = m - i;
		}
		if (m < i){
			break;
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << ' ';
	}
}