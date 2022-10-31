#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
  
using namespace std;
  
int n, m, a[1234], b[1234], mi=123456;

int main(){
	cin>> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int j = 0; j < n; j++){
		int z = a[j] , k=0;
		for (int i = 0; i < z; i++){
			cin >> b[i];
			k+=15+(b[i]*5);
		}

		mi = min(k , mi);
	
	}
	cout << mi;

}