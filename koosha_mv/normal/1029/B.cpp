#include<iostream>
using namespace std;
long long x,a[200009];
int main(){
	long long mx=0,gh,n,t=1;cin>>n;
	cin>>gh;
	for(long long i=0;i<n-1;i++){
		cin>>x;
		if(x<=gh*2)
			t++;
		else{
			mx=max(mx,t);
			t=1;
		}
		gh=x;
	}
	mx=max(mx,t);
	cout<<mx;
}