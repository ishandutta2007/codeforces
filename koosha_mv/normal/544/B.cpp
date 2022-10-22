#include<iostream>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	if(k>(n*n+1)/2){
		cout<<"NO";
		return 0;}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(k && (i+j)%2==0){
				k--;
				cout<<'L';}
			else
				cout<<'S';}
		cout<<endl;}
}