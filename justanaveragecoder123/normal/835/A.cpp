#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll s,a,b,c,d;
	cin>>s>>a>>b>>c>>d;
	ll x=0,y=0;
	x=2*c+s*a;
	y=2*d+s*b;
	if(x<y) {
		cout<<"First\n";
	}else if(x==y) {
		cout<<"Friendship\n";
	}else {
		cout<<"Second\n";
	}
	
	return 0;
	
}