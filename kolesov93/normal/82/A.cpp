#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	string nm[5] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
	long long cnt = 5,n;
	cin >> n;
	while (n > cnt) { 
		n -= cnt;
		cnt *= 2;
	}
	
	long long c = cnt / 5;
	int ans = 0;
	while (n > c) {
		n -= c;
		ans++;
	}
	
	cout << nm[ans] << endl;
	
	return 0;
}