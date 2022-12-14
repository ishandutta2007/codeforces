#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,t,a,i,mn,mx;
void f(ll x){
	mx=max(mx,x%10),mn=min(mn,x%10);
	if(x<10)return ;
	f(x/10);
}
int main(){
	cin>>t;
	while(t--){
		cin>>a>>k;--k;
		for(i=1;i<=k;++i){
			mx=0,mn=9;
			f(a);
			if(!mn)break;
			a+=mn*mx;
		}
		cout<<a<<"\n";
	}
}