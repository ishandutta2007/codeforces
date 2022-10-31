#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int a , b , c , d[123] , ma;

int main(){
	cin >> a >> b >> c;
	d[0] = a + b + c;
	d[1] = a * b * c;
	d[2] = (a + b) * c;
	d[4] = (b + c) * a;
	for (int i = 0; i < 5; i++)
		if (d[i] > ma) ma = d[i];
	cout << ma;





	return 0;
}