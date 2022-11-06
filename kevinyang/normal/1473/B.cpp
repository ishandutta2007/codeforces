#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		string b;
		cin >> b;
		if(a.length()>b.length())swap(a,b);
		int lcm = a.length()*b.length()/gcd(a.length(),b.length());
		string a2 = "";
		for(int i = 0; i<lcm/a.length(); i++){
			a2+=a;
		} 
		string b2 = "";
		for(int i = 0; i<lcm/b.length();i++){
			b2+=b;
		}
		if(a2==b2){
			cout << a2 << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}