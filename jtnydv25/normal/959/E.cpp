#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
int main(){
	long long n;
	cin >> n;
	long long ans = 0;
	for(int i = 0; i <= 50; i++){
		ans += ((1 + ((n - 1) >> i)) >> 1) << i;
	}
	cout << ans;
}