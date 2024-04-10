#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(min(a+b+c, 2*a+2*c), min(2*a+2*b, 2*b+2*c)) << endl;
	return 0;
}