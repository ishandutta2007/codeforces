#include<iostream>
using namespace std;
long long a[100009];
int main(){
	long long n,f=0,sum=0,mx=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];sum+=a[i],mx=max(mx,a[i]);
		f+=a[i]%2;}
	if(f%2==1 || sum/2<mx)
		cout<<"NO";
	else cout<<"YES";
}