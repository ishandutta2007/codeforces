#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c,l,res;

void get(ll x,ll lim,ll z){
	ll y=min(z,lim-x)+1;
	if(y<0){return;}
	res-=y*(y+1)/2;
}

int main(){
	cin>>a>>b>>c>>l;
	res=(l+1)*(l+2)*(l+3)/6;
	for(int i=0;i<=l;i++){
		get(b+c,a+i,l-i);
		get(a+c,b+i,l-i);
		get(b+a,c+i,l-i);
	}
	cout<<res;
}