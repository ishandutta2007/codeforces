#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int ans = 0;
		for(int i = 1; i<n; i++){
			int a = arr[i]; int b = arr[i-1];
			if(a<b)swap(a,b);
			int cnt = 0;
			while(a>b){
				b*=2;
				if(a<=b)break;
				cnt++;
			}
			ans+=cnt;
		}
		cout << ans << "\n";
	}
	return 0;
}