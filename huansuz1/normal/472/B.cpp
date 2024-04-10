#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

	long m,n,a[2009],k,t;


int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m;
		a[m]++;
	}
	long z = 0, i = 2000 , max = 0 , sum = 0;
	
	t = k;
	for (int i = 2000; i >= 1; i--){
		if (a[i]>0){
			while (a[i] != 0){
				a[i]--;
				z++; 
				if (i > max) max = i;
				if (z == t) { sum += (max - 1) * 2; max = 0; z = 0; }
			}
		}
	
	}
	if (max > 0) cout << sum + ((max - 1) * 2); else cout << sum;

	return 0;
}