#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> a ( n);
	int m=200000;
	for(int i=0;i<n;i++){
		cin >> a[i];
		m = min(m , a[i]);
	}
	cout << 2 + (m ^ a[2]);
}