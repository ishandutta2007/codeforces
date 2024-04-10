#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,a,b,c;
	cin >> n;
	for (ll i=0; i<n ;i++){
		cin >> a >> b >> c;
		if (b*2<=c){
			cout << a*b;
		}
		else{
			if (a%2==0){
				cout << (a/2)*c;
			}
			else{
				cout << (a/2)*c+b;
			}
		}
		cout << '\n';
	}
	return 0;
}