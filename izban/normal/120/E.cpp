#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		cout << !(a%2) << endl;
	}
	return 0;
}