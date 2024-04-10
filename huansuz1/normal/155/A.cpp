#include <iostream>
#include <algorithm>
using namespace std;
 
int  a[1234],n,ma,mi,z;

int main(){
     cin>>n;
	for (int i = 0; i < n; i++){ 
			cin>>a[i];
      }
     ma=a[0]; mi=a[0];
     for (int i=1; i<n; i++)    {
     	if (a[i]>ma) { ma=a[i]; z++;}
     	if (a[i]<mi) { mi=a[i]; z++;}
     	
     	}
     cout<<z;
      
     
     return 0;
}