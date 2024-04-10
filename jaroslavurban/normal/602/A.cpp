#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	ll a=0,b=0;
	int n,base;cin>>n>>base;
	ll mul=1;
	for(int i=1;i<n;++i)mul*=base;
	for(int i=0;i<n;++i){ll tmp;cin>>tmp;a+=tmp*mul;mul/=base;}
	cin>>n>>base;
	mul=1;
	for(int i=1;i<n;++i)mul*=base;
	for(int i=0;i<n;++i){ll tmp;cin>>tmp;b+=tmp*mul;mul/=base;}
	if(a<b)cout<<'<'<<endl;
	else if(a>b)cout<<'>'<<endl;
	else cout<<'='<<endl;
}