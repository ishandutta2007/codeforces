#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,m,i;
	string a[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
	cin >> n;
	m=n-1;
	n=(n-1)/5+1;
	i=-1;
	while (n){
		n/=2;
		i+=1;
	}
	if (i){
		m-=(pow(2,i)-1)*5;
		m/=pow(2,i);
	}
	cout << a[m];
	return 0;
}