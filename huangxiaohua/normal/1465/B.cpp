#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll sb;
ll chk(ll sb){
	ll a=sb;
	while(sb){
		if(sb%10){
			if(a%(sb%10)){return chk(a+1);}
		}
		sb/=10;
	}
	return a;
}

int main(){
	cin>>t;
	while(t--){
		cin>>sb;
		printf("%lld\n",chk(sb));
	}
}