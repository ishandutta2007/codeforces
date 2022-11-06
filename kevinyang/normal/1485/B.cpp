#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q,k;
	cin >> n >> q >> k;
	vector<int>arr(n+5); 
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>psa(n+5);
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]+arr[i+1]-arr[i-1]-2;
	}
	while(q--){
		int a,b;
		cin >> a >> b;
		cout << psa[b-1]-psa[a] +k-arr[b-1]+arr[a+1]-3 << "\n";
	}
	return 0;
}