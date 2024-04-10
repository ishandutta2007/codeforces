#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

int ask(int x){
	cout << "? " << x << '\n'; cout.flush();
	int in; cin >> in;
	return in;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> chk(n + 1);
		int t = 0;
		vector<int> ans(n + 1);
		for(int i = 1; i <= n; ++i){
			if(chk[i]){
				continue;
			}
			vector<int> now;
			while(true){
				int rv = ask(i);
				if(chk[rv]){
					break;
				}
				now.push_back(rv);
				chk[rv] = 1;
			}
			int sp = ((int)now.size() * 100000 - t + 1) % (int)now.size();
			int pp = i;
			for(int j = sp; j < (int)now.size(); ++j){
				ans[pp] = now[j];
				pp = now[j];
			}
			for(int j = 0; j < sp; ++j){
				ans[pp] = now[j];
				pp = now[j];
			}
			t += (int)now.size() + 1;
		}
		cout << "! ";
		for(int i = 1; i <= n; ++i){
			cout << ans[i] << ' ';
		}
		cout << '\n'; cout.flush();
	}
	return 0;
}