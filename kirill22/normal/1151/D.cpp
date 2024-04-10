#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<pair<int,pair<int,int>>> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i].second.first >> a[i].second.second;
		a[i].first=a[i].second.first-a[i].second.second;
	}
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=0;i<n;i++){
		ans+= a[i].second.first*(n-1-i)+ a[i].second.second *(i );
	}
	cout << ans;
	
}