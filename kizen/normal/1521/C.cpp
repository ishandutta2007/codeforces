#include <bits/stdc++.h>
#define int long long
using namespace std;

void out(int a, int b, int c, int d){
	cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	cout.flush();
}

signed main(){
	//freopen("con", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int npos;
		for(int i = 1; i <= n; i += 2){
			if(i == n){
				--i;
			}
			out(1, i, i + 1, n - 1);
			int val; cin >> val;
			if(val == n){
				npos = i + 1;
				break;
			}
			if(val == n - 1){
				out(1, i + 1, i, n - 1);
				cin >> val;
				if(val == n){
					npos = i;
					break;
				}
			}
		}
		vector<int> ans(n + 1);
		ans[npos] = n;
		for(int i = 1; i <= n; ++i){
			if(ans[i]){
				continue;
			}
			out(2, npos, i, 1);
			int val; cin >> val;
			if(val >= 3){
				ans[i] = val;
			}
		}
		vector<int> need;
		for(int i = 1; i <= n; ++i){
			if(!ans[i]){
				need.push_back(i);
			}
		}
		out(1, need[0], need[1], 1);
		int val; cin >> val;
		if(val == 2){
			ans[need[0]] = 1, ans[need[1]] = 2;
		}
		else{
			ans[need[0]] = 2, ans[need[1]] = 1;
		}
		cout << "! ";
		for(int i = 1; i <= n; ++i){
			cout << ans[i] << ' ';
		}
		cout << '\n'; cout.flush();
	}
	return 0;
}