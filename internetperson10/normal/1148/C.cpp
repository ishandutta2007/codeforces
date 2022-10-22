#include <bits/stdc++.h>
#define emplace_back push_back

using namespace std;

int nums[300005];
int num[300005];
int pos[300005];
vector<pair<int, int>> swaps;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int a=1; a<=n; a++) {
		cin >> num[a];
		nums[a] = num[a];
		pos[num[a]]=a;
	}
	for(int a=1; a<=n; a++) {
		if(a==pos[a]) continue;
		int k = num[a];
		swap(num[a], num[pos[a]]);
		bool l1=(a<=n/2), l2=(pos[a]<=n/2);
		if(l1 && l2) {
			swaps.push_back({a, n});
			swaps.push_back({pos[a], n});
			swaps.push_back({a, n});
		}
		else if(l1 || l2) {
			if(abs(a-pos[a])>=n/2) {
				swaps.emplace_back({a, pos[a]});
			}
			else if(a<pos[a]) {
				swaps.emplace_back({a, n});
				swaps.emplace_back({pos[a], 1});
				swaps.emplace_back({1, n});
				swaps.emplace_back({a, n});
				swaps.emplace_back({pos[a], 1});
			}
			else {
				swaps.emplace_back({a, 1});
				swaps.emplace_back({pos[a], n});
				swaps.emplace_back({1, n});
				swaps.emplace_back({a, 1});
				swaps.emplace_back({pos[a], n});
			}
		}
		else {
			swaps.emplace_back({a, 1});
			swaps.emplace_back({pos[a], 1});
			swaps.emplace_back({a, 1});
		}
		pos[k]=pos[a];
		pos[a]=a;
		//cout << '\n';
	}
	cout << swaps.size() << '\n';
	for(int a=0; a<swaps.size(); a++) {
		cout << swaps[a].first << ' ' << swaps[a].second << "\n";
	//	swap(nums[swaps[a].first], nums[swaps[a].second]);
		//for(int b=1; b<=n; b++) cout << nums[b] << ' ';
		//cout << '\n';
	}
}