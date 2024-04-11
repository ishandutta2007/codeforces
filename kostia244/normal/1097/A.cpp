#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

string a, b;

int main() {
	getline(cin, a);
	getline(cin, b);
	for(auto& i : b)
		if(i == a[0] || i == a[1]) {
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}