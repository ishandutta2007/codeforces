#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l,r,n,c,t,m,ma,z,ans,a[123456],b[123456],x;

int main(){
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>a[i]>>b[i];
		if (i>0 && a[i]-a[i-1]<abs(b[i]-b[i-1])) x=1;
	}
	if (x==1) {cout<<"IMPOSSIBLE"; exit(0);}
	ma=a[0]-1+b[0];
	for (int i=1; i<m; i++){
		int k=a[i]-a[i-1];
		int p=abs(b[i]-b[i-1]);
		int mi=(b[i],b[i-1]);
		k-=p;
		p=max(b[i],b[i-1]);
		ma=max(ma,p+(k/2));
	}
	ma=max(ma,(n-a[m-1]+b[m-1]));
	cout<<ma;

//	4 3 4 5 6 7 6 5
//	1 2 3 4 5 6 7 8

return 0;
}