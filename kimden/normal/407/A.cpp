#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main(){
	int a,b,i,j;
	int k,l,m;
	cin >> a >> b;
	for(i=1;i<a;i++){
		if(sqrt(a*a-i*i)==floor(sqrt(a*a-i*i))){
			k = sqrt(a*a-i*i);
			l = (i*b)/a;
			m = (k*b)/a;
			if(l*a==i*b && m*a==k*b && k!=l){
				cout << "YES\n0 0\n" << i << " " << k << "\n" << -m << " " << l;
				return 0;
			}
		}
	}
	cout << "NO";
    return 0;
}