#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n , a[4] , z , d;


int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
	z++;
	cin >> d;
	a[z]+=d;
	if (z==3) z=0;
	}
	if (a[1] > a[2] && a[1] > a[3]) cout << "chest"; else
	if (a[2] > a[1] && a[2] > a[3]) cout << "biceps"; else
		cout << "back";
	

	
		
	
	return 0;
}