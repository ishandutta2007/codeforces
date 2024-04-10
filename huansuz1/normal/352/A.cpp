#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,e,d,p;
int a,b;
long long s;
 
int main(){
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>d;
		if (d==5) {a++; s+=5;} else b++;
	}

	for (int i=a-1; i>=0; i--){

	     if (s%9==0 && b>0) {
	     	for (int j=0; j<=i; j++)
	     		cout<<5;
	     	for (int j=0; j<b; j++)	
	     	cout<<0;
	          exit(0);
	     }
	     s-=5;
	     }
	     if (b>0) cout<<0; else cout<<-1;
	return 0;
}