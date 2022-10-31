#include <iostream>
#include <string>

using namespace std;

int n , m , z , a[123456] , x , s;

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i] + 10;
		x += a[i];
	}
	s -= 10;
	if (s > m) cout << -1; else cout << (m-x) / 5;



}