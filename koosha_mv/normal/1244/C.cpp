#include<iostream>
using namespace std;
int main(){
	long long n,p,w,d,x,y,z,j;cin>>n>>p>>w>>d;
	for(long long i=0;i<w;i++){
		j=d*i;
		if((p-j)%w==0){
			x=(p-j)/w;
			z=n-i-x;
			if(z>=0 && x>=0){
				cout<<x<<" "<<i<<" "<<z;
				return 0;}
			break;}}
	cout<<-1;}