#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int low = 1; int high = n+1; int mid = (low+high)/2;
	while(low+1<high){
		vector<int>arr2(n+1);
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			if(arr[i]>=mid)arr2[i] = 1;
			else arr2[i] = -1;
			psa[i] = psa[i-1]+arr2[i];
		}
		bool f = false;
		set<int>s;
		for(int i = k; i<=n; i++){
			s.insert(psa[i-k]);
			int mn = *s.begin();
			if(psa[i]-mn>=1)f = true;
		}
		if(f){
			low = mid;
		}
		else{
			high = mid;
		}
		mid = (low+high)/2;
	}
	cout << low << "\n";
	return 0;
}