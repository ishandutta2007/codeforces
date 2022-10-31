#include <iostream>
using namespace std;
int main() {
	long long n, m, s = 0, x, y, z = 0,k;
	cin >> n >> m;
	if (n == 1 || m == 0) {cout<<n<<" "<<n; return 0;}
	k = m;
	while(m!=0){
		z += 2;
		m--;
		if (z >= n) { z = n;  break; }
	}
	y = n - z;
	for (int i = 2; i <= n; i++)
	{
		s += i - 1;
		if (s >= k) 
		{ 
			cout<<y<<" "<<n - i; 
			return 0; 
		}
	}
	
	
	return 0;
}