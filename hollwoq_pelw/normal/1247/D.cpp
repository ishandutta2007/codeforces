#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	long long ans=0;
	cin >> n >> k;

	map<vector<pair<int, int> >, int> mp;

	for(int i=0; i<n; ++i) {
		int ai;
		cin >> ai;

		vector<pair<int, int> > v1, v2;

		for(int j=2; j*j<=ai; ++j) {
			int pow=0;
			while(ai%j==0) {
				++pow;
				ai/=j;
			}
			if(pow%k) {
				v1.push_back(make_pair(j, pow%k));
			}
		}

		if(ai>1) {
			v1.push_back(make_pair(ai, 1));
		}

		for(int j=0; j<v1.size(); ++j) {
			v2.push_back(make_pair(v1[j].first, k-v1[j].second));
		}
		
		ans+=mp[v2];
		mp[v1]++;
	}

	cout << ans;

	return 0;
}