using namespace std;
#include<bits/stdc++.h>
long long n,m,x[300001],p;
long long g;
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x[i];
		if(i==2){
			g = x[2]-x[1];}
		else if(i>2){
			g = __gcd(g,x[i]-x[i-1]);}}
	for(long long i=1;i<=m;i++){
		cin>>p;
		if(g%p==0){
			cout<<"YES"<<endl<<x[1]<<" "<<i;
			return 0;}}
	cout<<"NO"<<endl;
}