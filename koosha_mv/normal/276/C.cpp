#include<iostream>
#include<algorithm>
using namespace std;
long long b=0,a[300009],s[300009],l[300009];
int main(){
	long long n,m,x,y,ans=0;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++){
		cin>>x>>y;
		l[x-1]++;l[y]--;}
	for(int i=0;i<n;i++){
		b+=l[i];
		s[i]=b;}
	sort(s,s+n);sort(a,a+n);
	for(int i=0;i<n;i++){ans+=a[i]*s[i];}
	cout<<ans;
}