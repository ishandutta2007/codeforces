#include<iostream>
using namespace std;
int a[100001];
int main(){
	int n,sum=0,s2=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];}
	if(n==1){
		cout<<1<<" "<<0;
		return 0;}
	float k=float(sum)/2;
	int p=0,s1=0,o=0;
	while(s2<k){
		s2+=a[p];
		p++;	
	}
	while(s1<k){
		s1+=a[n-1-o];
		o++;
	}
	if(s2<=s1)
		cout<<p<<" "<<n-p;
	else
		cout<<p-1<<" "<<n-p+1;}