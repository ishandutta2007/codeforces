#include<iostream>
using namespace std;
long long l,t,a[1000],b[1000],c[1000],d[1000],e=1e9+7,n;
int gh(int x){if(x==0) return 999; return x-1;}
int main(){
	cin>>n;
	a[0]=1;b[0]=1;c[0]=1;d[0]=0;a[1]=2;b[1]=2;c[1]=2;d[1]=3;
	for(long long i=2;i<n;i++){
		l=i%1000;
		t=gh(l);
		d[l]=(a[t]+b[t]+c[t])%e;a[l]=(d[t]+b[t]+c[t])%e;b[l]=(a[t]+d[t]+c[t])%e;c[l]=(a[t]+b[t]+d[t])%e;
	}	
	cout<<d[(n-1)%1000];
}