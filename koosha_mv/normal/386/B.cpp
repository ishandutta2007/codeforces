#include<iostream>
using namespace std;
int a[2000]={0};
int main(){
	int n,t;
	cin>>n;
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		a[y]++;}
	cin>>t;
	int maxx=1, s2=0,s1=0,j=0;
	s2=t+1;
	for(int i=0;i<=t;i++){
		j+=a[i];}
	while(s2<2000){
		maxx=max(maxx,j);
		j+=a[s2];
		s2++;
		j-=a[s1];
		s1++;
		maxx=max(maxx,j);}
	cout<<maxx;}