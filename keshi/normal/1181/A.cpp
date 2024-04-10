#include <bits/stdc++.h>
using namespace std;
long long x, y, z, a, b;
int main(){
	cin >> x >> y >> z;
	b = min( x % z - (x % z + y % z) % z , y % z - (x % z + y % z) % z);
	a = (x % z + y % z) / z;
	if(!a){
		b = 0;
	}
	cout << (x + y) / z << ' ' << b;
	return 0;
}