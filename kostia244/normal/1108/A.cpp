#include <bits/stdc++.h>
using namespace std;
string s;
int n, l1, l2, r1, r2;
int main() {
	cin >> n;
	while(n--) {
		cin >> l1 >> r1 >> l2 >> r2;
		if(l1 == l2)
			l2++;
		cout << l1  << " " << l2;
		cout << "\n";
	}
}