#include <bits/stdc++.h>
using namespace std;
int n, k, a[200100];
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	if(k == 0){
		if(a[0] > 1){
			cout << 1;
		}
		else{
			cout << -1;
		}
	}
	else if(k == n){
		cout << a[k - 1];
	}
	else if(a[k - 1] == a[k]){
		cout << -1;
	}
	else{
		cout << a[k - 1];
	}
	return 0;
}