#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int l,r;
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll d,k;cin>>d>>k;
		ll r=0,l=0;
		while(r*r+l*l<=d*d)if(r<=l)r+=k;
		else l+=k;
		if(l==r)cout<<"Ashish\n";
		else cout<<"Utkarsh\n";
	}
}