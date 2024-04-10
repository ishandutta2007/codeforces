#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		bool f = false;
		if(gcd(a,b)==1)f = true;
		if(!f)cout << "Infinite\n";
		else cout << "Finite\n";
	}
	return 0;
}