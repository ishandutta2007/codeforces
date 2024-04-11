#include<iostream>
using namespace std;
int a[10002]={0};
int main(){
	int n,x,y;
	cin>>n;
	int j=0;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		a[x]++;
		a[y]++;}
	for(int i=0;i<n+1;i++){
		j+=a[i]*(a[i]-1)/2;}
	cout<<j;}