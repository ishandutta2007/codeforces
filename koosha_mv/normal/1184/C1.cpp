#include<bits/stdc++.h>
using namespace std;
long long n,x[43],y[43];
int main(){
	cin>>n;
	n=4*n+1;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	for(int i=0;i<=50;i++)
	for(int j=0;j<=50;j++)
	for(int k=0;k<=50;k++){
		long long cnt=0,xx=111,yy=111;
		for(int ps=0;ps<n;ps++)
			if(!(x[ps]==i+k||x[ps]==i||y[ps]==j||y[ps]==j+k)||x[ps]>i+k||y[ps]>j+k||x[ps]<i||y[ps]<j)
				cnt++,
			xx=x[ps],yy=y[ps];
	if(cnt==1){
		cout<<xx<<' '<<yy;
	return 0;
	}
}
}