#include <bits/stdc++.h>
#define int long long
using namespace std;

void out(int x, int y){
	cout << "? " << x << ' ' << y << '\n';
	cout.flush();
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, t; cin >> n >> t;
	vector<int> cnt;
	int first = 1;
	while(t--){
		int k; cin >> k;
		if(first){
			for(int i = 1; i <= n; i += 32){
				out(1, min(n, i + 31));
				int val; cin >> val;
				cnt.push_back(min(n, i + 31) - val);
			}
			first = 0;
		}
		int pos = 0, sum = 0;
		while(sum + cnt[pos] < k){
			++pos;
		}
		int low = pos * 32 + 1, high = min(n, low + 31);
		while(low < high){
			int mid = (low + high) >> 1;
			out(1, mid);
			int val; cin >> val;
			if(k <= mid - val){
				high = mid;
			}
			else{
				low = mid + 1;
			}
		}
		cout << "! " << low << '\n'; cout.flush();
		for(int i = pos; i < (int)cnt.size(); ++i){
			--cnt[i];
		}
	}
	return 0;
}