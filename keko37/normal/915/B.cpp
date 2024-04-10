#include<iostream>

using namespace std;

int n, pos, l, r;

int main () {
	cin >> n >> pos >> l >> r;
	if (pos<l) {
		cout << l-pos+1 + (r<n)*(r-l+1);
	} else if (r<pos) {
		cout << pos-r+1 + (1<l)*(r-l+1);
	} else {
		cout << min((1<l)*(pos-l+1) + (r<n)*(r-l+1), (r<n)*(r-pos+1) + (1<l)*(r-l+1));
	}
	return 0;
}