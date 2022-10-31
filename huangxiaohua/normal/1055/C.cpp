#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll res,a,b,c,d,e,f,sb,l1,l2,x,y;

int main() {
	ios::sync_with_stdio(0);
	cin>>a>>b>>c>>d>>e>>f;
	sb=__gcd(c,f);
	
	d+=1e9*sb+sb;
	e+=1e9*sb+sb;
	
	x=a+((d-a)/sb)*sb;
	y=x+b-a;
	
	for(i=0;i<=100;i++){
		res=max(res,(min(e,y)-max(d,x)+1));
		x+=sb;y+=sb;
	}
	
	y=b+((e-b)/sb)*sb;
	x=y-(b-a);
	
	for(i=0;i<=100;i++){
		res=max(res,(min(e,y)-max(d,x)+1));
		x+=sb;y+=sb;
	}
	
	cout<<res;
	
}