#include <bits/stdc++.h>
using namespace std;
int n, a[200100], b, t;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	t = 1;
	for (int i = 0; i < n; i++){
		if (a[i] >= t){
			t++;
		}
	}
	cout << t - 1;
	return 0;
}