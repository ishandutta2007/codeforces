#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n , m , k , a[1234] , z;

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		if ( a[i] == 1) 
			if ( m > 0 ) m--;  else z++;
		if ( a[i] == 2)
			if ( k > 0 ) k--;  else 
			if ( m > 0 ) m--;  else  
			z++;
		
	}
	cout << z;






	return 0;
}