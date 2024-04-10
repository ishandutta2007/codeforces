#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	map<int,int>hm;
	int mx = 0;
	for(int i = 0; i<n; i++){
		hm[arr[i]]++;
		mx = max(mx,hm[arr[i]]);
	}
	cout << n-mx << "\n";
	return 0;
}