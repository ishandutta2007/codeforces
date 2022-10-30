#include<iostream>
#include<string>
#include<algorithm>
  
using namespace std;
 
long long n,a[123456],m,ans;
int main(){
	cin>>n;
    for (int i=0; i<n ;i++){
		cin>>m;
		a[m]++;
	}
	for (int i=1; i<=100009; i++)
		a[i]=(long long)i*a[i];
	for (int i=1; i<=100009; i++){
		if (i>1){
			a[i]+=a[i-2];
		}
		if (a[i-1]>a[i])
			a[i]=a[i-1];
	}
	cout<<a[100008];
	
                                                                                          
return 0;
}