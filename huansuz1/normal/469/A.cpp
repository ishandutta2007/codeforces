#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,p,q,a[1236],b[1236],c[1234];
 
int main(){
	cin>>n;
	cin>>q; 
	for (int i=0; i<q; i++) {
		cin>>a[i];
		c[a[i]]=1;
		}
	cin>>p;
	for (int i=0; i<p; i++) {
		cin>>b[i];
		c[b[i]]=1;
		}
	for (int i=1; i<=n; i++)
		if (c[i]==0) {cout<<"Oh, my keyboard!"; exit(0);}
	cout<<"I become the guy.";

	return 0;
}