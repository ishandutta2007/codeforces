#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n , times = 9;
	int ans = 0;
	cin >> n;
	while(n >= times){
		n -= times;
		ans += 9;
		times *= 10;
	}
	while(n){
		ans += n % 10;
		n /= 10;
	}
	cout << ans;
	return 0;
}