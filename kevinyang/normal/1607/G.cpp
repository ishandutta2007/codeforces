#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<pair<int,int>>arr(n+1);
		vector<pair<int,int>>ans(n+1);
		int a = 0; int b = 0;
		for(int i = 1; i<=n; i++){
			int x,y;
			cin >> x >> y;
			arr[i] = {x,y};
			a+=x; b+=y;
		}
		for(int i = 1; i<=n; i++){
			if(arr[i].first>=m){
				arr[i].first-=m;
				a-=m;
				ans[i].first+=m;
			}
			else{
				a-=arr[i].first;
				ans[i].first+=arr[i].first;
				b-=m-arr[i].first;
				ans[i].second+=m-arr[i].first;
				arr[i].second-=(m-arr[i].first);
				arr[i].first = 0;
			}
		}
		if(a>=b){
			cout << abs(a-b) << "\n";
			for(int i = 1; i<=n; i++){
				cout << ans[i].first << " " << ans[i].second << "\n";
			}
			continue;
		}
		for(int i = 1; i<=n; i++){
			int rem = (b-a)/2;
			if(min(arr[i].second,min(m,ans[i].first))<rem){
				int v = min(arr[i].second,min(m,ans[i].first));
				a+=v; b-=v;
				ans[i].first-=v; ans[i].second+=v;
			}
			else{
				int v = rem;
				a+=v; b-=v;
				ans[i].first-=v; ans[i].second+=v;
				break;
			}
		}
		cout << abs(a-b) << "\n";
		for(int i = 1; i<=n; i++){
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
	return 0;
}