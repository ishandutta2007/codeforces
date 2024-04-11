#include<iostream>
using namespace std;
long long a[1000002],n;
int main(){
	cin>>n;
	long long s=1,tmn=0,tms=0,tmsa=0,tmna=0,x,y;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0)
			s*=-1;
		if(s==1)
			tms++;
		else
			tmn++;}
	tmsa=tms;tmna=tmn;
	for(long long i=1;i<n;i++){
		x=tms;
		y=tmn;
		if(a[i-1]>0){tms--;}
		else {y--;tmn=x;tms=y;}
		tmsa+=tms;tmna+=tmn;}
	cout<<tmna<<" "<<tmsa;
	
	
}