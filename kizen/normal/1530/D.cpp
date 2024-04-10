#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), did(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i]; --a[i]; did[a[i]] = 1;
		}
		int first = -1;
		for(int i = 0; i < n; ++i){
			if(!did[i]){
				first = i;
			}
		}
		vector<int> chk(n), same, ans(n, -1), emp;
		if(first != -1 && !chk[a[first]]){
			chk[a[first]] = 1;
			ans[first] = a[first];
		}
		for(int i = 0; i < n; ++i){
			if(i == first) continue;
			if(!chk[a[i]]){
				chk[a[i]] = 1;
				ans[i] = a[i];
			}
		}
		for(int i = 0; i < n; ++i){
			if(!chk[i]){
				emp.push_back(i);
			}
		}
		int no;
		for(int i = 0; i < n; ++i){
			if(ans[i] == -1){
				ans[i] = emp.back();
				emp.pop_back();
				if(i == ans[i]){
					same.push_back(i);
				}
				else no = i;
			}
		}
		for(int i = 0; i < (int)same.size(); ++i){
			ans[same[i]] = same[(i + 1) % (int)same.size()];
		}
		if((int)same.size() == 1){
			swap(ans[same[0]], ans[no]);
		}
		int sum = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] == ans[i]) ++sum;
		}
		cout << sum << '\n';
		for(int i = 0; i < n; ++i){
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}