#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,v,k,z;
int a[1236],b[1234];
 
int main(){
	cin>>n>>v;
	for (int i=0; i<n; i++) {
		cin>>k;
		int p=0;
		for (int j=0; j<k; j++) {
			cin>>a[j];          
			if (a[j]<v) p=1;
			}
		if (p==1) b[z++]=i+1;
		}
	cout<<z<<endl;
	for (int i=0; i<z; i++)
		cout<<b[i]<<" ";
	return 0;
}