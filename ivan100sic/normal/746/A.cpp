#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = min(min(a, b/2), c/4);
	cout << 7*x;
}