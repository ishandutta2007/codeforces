#include<iostream>
#include<cmath>
using namespace std;
long long r,x,y,nx,ny,flag;
double q,w,b;

int main()
{
	cin>>r>>x>>y>>nx>>ny;
	q=(x-nx)*(x-nx)+(y-ny)*(y-ny);
	w=(r*2)*(r*2);
	b=sqrt(q/w);
	if(b-((long long)b)>0) {flag=1;}
	cout<<((long long)b)+flag;
}