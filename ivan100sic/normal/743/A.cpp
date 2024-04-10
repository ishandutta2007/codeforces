#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, a, b;
string v;

int main() {
	cin >> n >> a >> b >> v;
	a--;
	b--;
	if (v[a] == v[b]) {
		cout << 0;
	} else {
		cout << 1;
	}
}