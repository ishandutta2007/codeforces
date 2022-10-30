// Hydro submission #62f21654da6f99552b33f582@1660032597806
#include<iostream>
using namespace std;
int main(){
	int n,a=0,b=0,c=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==1){
			a++; 
		}else if(arr[i]==2){
			b++;
		}else{
			c++;
		}
	} 
	if(a>=b&&a>=c){
	 cout<<b+c;
	}else if(b>a&&b>c){
	 cout<<a+c;
	}else{
	 cout<<a+b;
	}
     return 0;
}