#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;
int n,a[1234],x,y,p; 

int main(){
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i];         
		x+=a[i];
		}
	sort(a,a+n);
	
	for (int i=n-1; i>=0; i--){
	y+=a[i];   p++;
     if (y>x-y)  break;                        
     }
     cout<<p;
    
    }