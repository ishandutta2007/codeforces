#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,z;
int a[1236];
double s;
 
int main(){
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		s+=a[i];
		}

	printf("%.12lf",s/n);
	return 0;
}