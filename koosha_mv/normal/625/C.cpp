#include<iostream>
using namespace std;
int a[502][502];
int main(){
	int n,k,x=1;
	cin>>n>>k;k--;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			a[i][j]=x;
			x++;}}
	for(int i=0;i<n;i++){
		for(int j=k;j<n;j++){
			a[i][j]=x;
			x++;}}
	//cout<<(n-k)<<endl;
	x=(((n*n)-(n*(n-k))+1)*n)+((n)*(n-1)/2)*(n-k);cout<<x<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}