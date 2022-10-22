#include<iostream>
using namespace std;
int a[2],n,x;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){cin>>x;a[x-1]++;}
	if(a[0]>=1 && a[1]>=1){
		cout<<"2 1 ";
		a[0]--;a[1]--;}
	while(a[1]--) cout<<"2 ";
	while(a[0]--)	cout<<"1 ";}