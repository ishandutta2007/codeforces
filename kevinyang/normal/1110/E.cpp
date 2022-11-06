#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);

	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>arr2(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr2[i];
	}
	vector<int>a;
	bool f = true;
	vector<int>b;
	for(int i = 1; i<n; i++){
		a.push_back(arr[i+1]-arr[i]);
		b.push_back(arr2[i+1]-arr2[i]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a==b&&arr[1]==arr2[1]&&arr2[n]==arr[n])cout << "Yes\n";
	else cout << "No\n";
	return 0;
}