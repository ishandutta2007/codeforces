#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main(){
	lint a, b, c; cin >> a >> b >> c;
	lint ret = 2 * c;
	if(a == b) ret += a + b;
	else ret += min(a, b) * 2 + 1;
	cout << ret << endl;
}