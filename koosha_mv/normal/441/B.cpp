#include<iostream>
using namespace std;
int a[3002]={0};
int main(){
	int n,v,w,e;
	cin>>n>>v;
	for(int i=0;i<n;i++){
		cin>>w>>e;
		a[w]+=e;
	}
	int j=0,b;
	for(int i=1;i<3002;i++){
		b=v;
		j+=min(b,a[i-1]);
		b-=min(b,a[i-1]);
		j+=min(b,a[i]);
		a[i]-=min(b,a[i]);}
	cout<<j;}