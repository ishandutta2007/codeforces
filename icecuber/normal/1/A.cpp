#include <iostream>
using namespace std;

int main() {
	long long w, h, a;
	cin >> w >> h >> a;
	w = w/a+!!(w%a);
	h = h/a+!!(h%a);
	cout << w*h << endl;
	return 0;
}