#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main(){
	int n;
	cin >> n;
	if(n > 0){
		n = 4 + n%4;
	}
	int ret = 1;
	for(int i=0; i<n; i++) ret *= 8;
	ret %= 10;
	cout << ret;
}