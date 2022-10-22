#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	bool flag =true;
	ll n,m,k,h=0,ans=0;
	string s,s1;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> m >> k;
		h=h-m+k;
		ans=max(ans,h);
	}
	cout << ans;
	

	return 0;
}