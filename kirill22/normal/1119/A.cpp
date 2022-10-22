#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,b,c,ans=0;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if (a[0]!=a[n-1]){
		cout << n-1;
		return 0;
	}
	int mx=0;
	for(int i=0;i<n;i++){
		if (a[i]!=a[0]){
			mx=max(mx,max(n-i-1,i));
		}
	}
	cout << mx;
	
}