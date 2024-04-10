#include "bits/stdc++.h"
using namespace std;

long long x;

int main(){
	cin >> x;
	if (x <= 2){
		cout << -1;
		return 0;
	}
	if (x % 4 == 0){
		cout << 3*x/4 << ' ' << 5*x/4;
		return 0;
	}
	if (x % 4 == 2){
		x /= 2;
		
		long long m = x/2;
		long long n = x/2+1;
	
		cout << m*n*4 << ' ' << (m*m + n*n)*2 << endl;
		
		cin >> x;
		return 0;
	}
	
	long long m = x/2;
	long long n = x/2+1;
	
	cout << m*n*2 << ' ' << m*m + n*n << endl;

	return 0;
}