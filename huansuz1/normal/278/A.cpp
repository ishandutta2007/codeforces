#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int s,ss,n,p;
int x,y,a[12345];
 
int main(){
	cin>>n;
	for (int i=1; i<=n; i++) 
		cin>>a[i];

	cin>>x>>y;
	if (x==y) cout<<0; else {
		if (x>y)  {p=x; x=y; y=p; }
		
		for (int i=x	; i<y; i++)
			s+=a[i];
		for (int i=y; i<=n; i++)
			ss+=a[i];
		for (int i=1; i<x; i++)
		     ss+=a[i];
		if (s<ss) cout<<s; else cout<<ss;
	
	}

	
	
	
	return 0;
}