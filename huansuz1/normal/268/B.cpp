#include <iostream>
#include <algorithm>
using namespace std;
 
int  n;

int main(){
     cin>>n;
	int s=n,k=1;
	for (int i=n-1; i>=1; i--) {
     s+=i*k;
     k++;
	}
	cout<<s;	
     return 0;
}