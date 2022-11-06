#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	vector<int>ind(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		ind[arr[i]] = i;
	}
	int ans = 0;
	priority_queue<pair<int,int>>pq;
	for(int i = 1; i<=n; i++){
		pq.push({arr[i],i});
	}
	set<int>bad;
	bad.insert(0); bad.insert(n+1);
	for(int t = 1; t<=n; t++){
		pair<int,int>p = pq.top(); pq.pop();
		int val = p.first; int idx = p.second;
		int low = *--bad.lower_bound(idx); int high = *bad.lower_bound(idx);
		if(high-idx>idx-low){
			for(int i = low+1; i<idx; i++){
				int v = val-arr[i];
				assert(v>0);
				if(v>0&&v<=n&&ind[v]>idx&&ind[v]<high)ans++;
			}
		}
		else{
			for(int i = idx+1; i<high; i++){
				int v = val-arr[i];
				assert(v>0);
				if(v>0&&v<=n&&ind[v]<idx&&ind[v]>low)ans++;
			}
		}
		bad.insert(idx);
	}
	cout << ans << "\n";
	return 0;
}