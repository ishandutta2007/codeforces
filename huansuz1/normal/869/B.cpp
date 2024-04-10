#include <iostream>
using namespace std;

int main() {
	long long n,k,ans = 1 , t = 1;
	cin>>n>>k;
	if (k-n >= 10) {cout<<0; return 0;}
	if (k == n) {cout<<1; return 0;}
	for (int i = (n%100)+1; i <= (k%100); i++){
		ans = (ans *(i%10))%10;
		t = 0;
	}
	if (t) cout<<0; else
	cout<<ans;
	// your code goes here
	return 0;
}