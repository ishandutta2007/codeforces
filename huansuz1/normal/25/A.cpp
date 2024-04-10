#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,c,d,x,y;
int a[1236];
 
int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];          
		if (a[i]%2==0) {x=i+1; c++; } else {y=i+1; d++;}
		}
		if (c==1) cout<<x; else cout<<y;
	return 0;
}