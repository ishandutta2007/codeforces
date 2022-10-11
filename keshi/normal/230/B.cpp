#include <bits/stdc++.h>
using namespace std;
#define l long long int
bool tp(l n){
	l x=(l)sqrt(n);
	if (x*x!=n or n==1){
		return 0;
	}
	l i=2;
	while (i*i<=x){
		if (!(x%i)){
			return 0;
		}
		i++;
	}
	return 1;
}
int main(){
	int n;
	l a;
	cin >> n;
	string s="";
	while (n--){
		cin >> a;
		if (tp(a)){
			s+="YES\n";
		}
		else{
			s+="NO\n";
		}
	}
	cout << s;
	return 0;
}