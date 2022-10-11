#include <bits/stdc++.h>
using namespace std;

int n, a1, b1, a2, b2, ans;

int main(){
	cin >> n;
	while(n--){
		cin >> a2 >> b2;
		ans += max(0, min(a2, b2) - max(a1, b1) + 1);
		if(a1 == b1){
			ans--;
		}
		a1 = a2;
		b1 = b2;
	}
	cout << ++ans;
	return 0;
}