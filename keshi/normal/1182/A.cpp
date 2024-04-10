#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;

int main(){
	cin >> n;
	if(n%2){
		cout << 0;
		return 0;
	}
	ans = 1;
	for(int i = 0; i * 2 < n; i++){
		ans *= 2;
	}
	cout << ans;
	return 0;
}