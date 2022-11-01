#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;


int main() {
	long long n;
	cin >> n;
	long long newn = n / 2;
	long long res = 0;
	if(n % 2 == 0){
		res += (2 + n + -1 - (n - 1)) * newn / 2;
	}
	else {
		res += (2 + n - 1) * newn / 2;  
		res += (-1 - n) * (newn + 1) / 2;
	}
	cout << res << endl;

	return 0;
}