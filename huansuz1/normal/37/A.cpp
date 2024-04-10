#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int n , k , m , t , z = 1, zz = 1 , ma;
int a[1234];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a , a+n);
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1] ) z++;
		if (a[i] == a[i-1]) zz++; else {
		        if (zz > ma) ma = zz;
		        zz=1;			
		}
	}
	if (zz > ma) ma = zz;
	cout << ma << " " << z;

	return 0;
}