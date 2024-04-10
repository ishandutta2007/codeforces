// Hydro submission #62f219293f8efa55416cc0be@1660033321706
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	cin>>arr[1];
	for(int i=2;i<=n;i++){
		cin>>arr[i];
		if (abs(arr[i]-arr[i-1])>1){
			cout<<"NO";
		return 0;
		}
}
  cout<<"YES";
	return 0;
}