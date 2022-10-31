#include <iostream>
#include <string>

using namespace std;

int n , m , z , a[123456] , x , y;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == 25 ) x++;
		if (a[i] == 50 ) {
			if (x>0) { x--; y++; } else z=1; }
		if (a[i] == 100) {
			if (x > 0 && y > 0) { x--; y--; } else 
			if (x > 2) x-=3; else z=1;              
			
		} 

		}
	if (z == 1) cout << "NO"; else cout << "YES";



}