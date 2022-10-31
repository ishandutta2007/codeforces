#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,a,b,s;
 
int main(){
	cin>>n>>m>>a>>b;
	if (m*a<=b) cout<<n*a; else {
		while(n!=0){
			if (n>=m) { n-=m; s+=b; } else 
			if ((n*a)<b) { s+=n*a; n=0; } else {n=0; s+=b; }
		}

		cout<<s;
	}
		


	
	return 0;
}