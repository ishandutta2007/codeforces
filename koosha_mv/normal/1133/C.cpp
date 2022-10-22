#include<iostream>
#include<algorithm>
using namespace std;
long long a[200004];
int main(){
	long long n,p1=0,p2=1,mn=0,mx=0,b=1;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	mn=a[0];mx=a[0];
	while(p2<n){
		if(mx-mn<=5){
			mx=a[p2];
			b=max(b,p2-p1);
			p2++;
			if(mx-mn<=5)
				b=max(b,p2-p1);	
		}
		else{
			p1++;
			mn=a[p1];
		}
	}
	cout<<b;
}