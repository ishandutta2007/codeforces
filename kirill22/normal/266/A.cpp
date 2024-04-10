#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	bool flag =true;
	ll n,m,k,h,ans=0;
	string s,s1;
	cin >>n>>s ;
	for(int i=1;i<n;i++){
		if (s[i]==s[i-1]){
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}