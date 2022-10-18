#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((c == 0 && a == b) || (c != 0 && (b - a) / c * c == (b-a) && (b - a) / c >= 0)){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}