#include<iostream>
#include<cmath>
using namespace std;
long long h,n,k,t,p,w,o;
int i,j;
int main()
{
	cin>>h>>n;
	t=n;
	for(i=h-1;i>0;i--){
		k=1;
		for(j=i;j>0;j-=20){
			k*=((long long)1<<(min(20,j)));
		}
		if(t-p<=k){t=k+1-t+2*p;}
		else {p+=k;}
	}
	for(i=0;;i++){
		k=1;
		for(j=i;j>0;j-=20){
			k*=((long long)1<<(min(20,j)));
		}
		w=(t-1)/k;
		if(w==0){break;}
		o+=w;
	}
	cout<<o+h;
}