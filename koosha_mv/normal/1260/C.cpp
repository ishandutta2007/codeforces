#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long 
ll sagh(ll x,ll y){
	if(x%y==0) return x/y;
	return x/y+1;
}
ll lcm(ll a, ll b)  
 {  
    return (a*b)/(__gcd(a, b));  
 }  
int main(){
	ll mb,mr,t,r,b,k,g;
	cin>>t;
	f(i,0,t){
		cin>>r>>b>>k;
		if(r>b) swap(b,r);
		g=lcm(r,b);
		mb=g/b;
		mr=g/r-1;
		//cout<<mr<<" "<<mb<<endl;
		if(sagh(mr,mb)>=k) cout<<"REBEL"<<endl;
		else cout<<"OBEY"<<endl;
		t++;
		t--;
	}
}