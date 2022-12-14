#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<pair<int, int>> sum((int)6e6, {-1, -1});
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int val = a[i] + a[j];
			if(sum[val].first != -1){
				if(sum[val].first != i && sum[val].first != j){
					if(sum[val].second != i && sum[val].second != j){
						cout << "YES\n";
						++sum[val].first, ++sum[val].second;
						++i, ++j;
						cout << sum[val].first << ' ' << sum[val].second << ' ' << i << ' ' << j;
						return 0;
					}
				}
			}
			else{
				sum[val] = {i, j};
			}
		}
	}
	cout << "NO";
	return 0;
}