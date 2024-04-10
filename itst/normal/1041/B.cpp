#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll gcd(ll a , ll b){
	ll t = a % b;
	while(t){
		a = b;
		b = t;
		t = a % b;
	}
	return b;
}

int main()
{
	ll a , b , x , y;
	cin >> a >> b >> x >> y;
	ll t = gcd(x , y);
	x /= t;
	y /= t;
	cout << min(a / x , b / y);
 	return 0;
}