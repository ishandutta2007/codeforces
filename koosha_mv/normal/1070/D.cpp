#include<iostream>
using namespace std;
long long t(long long x,long long y){
	if(x%y==0)
		return x/y;
	return x/y+1;}
int main(){
	long long n,c,gh=0,x,p,sum=0;
	cin>>n>>c;
	for(long long i=0;i<=n;i++)	{
		if(i==n)
			x=0;
		else
			cin>>x;
		p=t(gh,c);
		x-=min(x,(p*c)-gh);
		sum+=p;
		gh=x;}
	cout<<sum;
}