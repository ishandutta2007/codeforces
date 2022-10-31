#include <iostream>
#include <algorithm>
using namespace std;
 
int  n,a[123456],b[123456],d[123456],ma;

int main(){
     
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i]>>b[i];   
		d[(a[i]*60)+b[i]]++;
		}
	for(int i=0; i<3000; i++)
		if (d[i]>ma) ma=d[i];
	cout<<ma;

     return 0;
}