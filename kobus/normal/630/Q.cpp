#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define mp make_pair
#define ld long double
#define MAXN 2123456
#define mod 998244353 
#define int long long
#define ld long double
#define pi acos(-1)

ld to_rad(int x){
	return pi*x*((ld)1.)/180;
}

long double a1(int l1){
	ld ab=sqrt((ld)3.)*l1*l1/4;
	ld h=sqrt((ld)6.)*l1/3;
	return ab*h/3;
}
long double a2(int l2){
	ld ab=l2*l2;
	ld h=sqrt((ld)2.)*l2/2;
	return ab*h/3;
}
long double a3(ld x){
	ld y=sqrt(x*x+x*x-2*x*x*cos(to_rad(108)));
	//cout<<x<<" "<<y<<endl;
	ld hy=sqrt(x*x-y*y/4);
	ld hp=sqrt(y*y-x*x/4);
	//cout<<endl<<"a "<<hy<<" "<<hp<<endl;
	ld ab=y*hy+x*hp/2;
	ld r=sqrt((ld)x*x/(2-2.*cos(to_rad(72))));
	ld h=sqrt((ld)x*x-r*r);
	//cout<<endl<<"a "<<r<<" "<<h<<endl;
	return ab*h/3;
}

int32_t main(){

	int a,b,c;
	cin>>a>>b>>c;
	cout<<setprecision(11)<<fixed;
	//cout<<a1(a)<<" "<<a2(b)<<" "<<a3(c)<<endl; 
	cout<<a1(a)+a2(b)+a3(c)<<endl; 

    return 0;
}