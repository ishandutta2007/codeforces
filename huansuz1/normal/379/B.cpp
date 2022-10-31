#include <iostream>

using namespace std;

int n , a[1234] , s , k , j;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	int p = 0;

	while (k != s) {
	
	if (a[j] != 0) { cout << 'P'; a[j]--; k++; }
	if (k == s) break; 

	if (j == n-1) p = 1;
	if (j == 0) p = 0;
	
	if (p == 0 )   { cout << 'R'; j++; } 
		else {
	        	cout << 'L'; j--;
		}
	}
	



	return 0;
}