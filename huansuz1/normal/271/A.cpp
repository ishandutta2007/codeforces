#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n,k,a,b,c,d;
int main(){
	cin>>n;
	while(n!=0){
		n++;
		k=n;
		a=k%10;
		k/=10;
		b=k%10;
		k/=10;
		c=k%10;
		k/=10;
		d=k%10;
		if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d) {cout<<n; break;}

	}
}