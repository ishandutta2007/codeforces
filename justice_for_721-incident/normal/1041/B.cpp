#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll g=gcd(c,d);
	c/=g;
	d/=g;
	cout << min(a/c,b/d) << endl;
}