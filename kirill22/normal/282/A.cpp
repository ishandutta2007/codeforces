#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k,h,ans=0;
	string s;
	cin >> n ;
	for(int i=0;i<n;i++){
		cin >> s;
		if  (s[1]=='+'){
			ans++;
		}
		else{
			ans--;
		}
		
	}
	cout << ans;
	return 0;
}