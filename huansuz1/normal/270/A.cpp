#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,a[123456],b[1234];
 
int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];           
		if (360%(180-a[i])==0)  cout <<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}