#include <iostream>
#include <algorithm>
using namespace std;
 
long long n,m,a[1234],z=1;

int main(){
     
	cin>>n>>m;
	if (n%2==0) {
		if (m<=n/2) cout<<(m*2)-1; else 
			cout<<((m-(n/2))*2);	
	} else {
		if (m<=(n/2)+1) cout<<(m*2)-1; else 
			cout<<((m-(n/2)-1)*2);	
	}
	
	
		 
	return 0;
}