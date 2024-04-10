#include <iostream>

using namespace std;

int c[5];
int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		c[tmp]++;
	}
	int one = (c[1]-c[3]-(c[2]%2)*2+3)/4;
	if (one < 0) one = 0;
	cout << c[4]+c[3]+(c[2]+1)/2+one << endl;
	return 0;
}