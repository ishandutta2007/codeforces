#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(a == b){
		cout << 2 * c + min(a, b) * 2;
	}
	else{
		cout << 2 * c + min(a, b) * 2 + 1;
	}
}