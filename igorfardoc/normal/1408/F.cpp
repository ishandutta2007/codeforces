#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<pair<int, int>> ans;

void build_good(vi& a) {
	if(a.size() == 1) {
		return;
	}
	vi fir(a.size() / 2);
	vi sec(a.size() / 2);
	for(int i = 0; i < a.size(); i++) {
		if(i < a.size() / 2) {
			fir[i] = a[i];
		} else {
			sec[i - a.size() / 2] = a[i];
		}
	}
	build_good(fir);
	build_good(sec);
	for(int i = 0; i < a.size() / 2; i++) {
		ans.push_back({a[i], a[a.size() - 1 - i]});
	}

}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    int now = 1;
    while(now * 2 <= n) {
    	now *= 2;
    }
    vi a(now);
    int need = n - now;
    for(int i = 0; i < now; i++) {
    	a[i] = i;
    }
    build_good(a);
    for(int i = 0; i < need; i+=2) {
    	ans.push_back({i, i + 1});
    }
    for(int i = need; i < n; i++) {
    	a[i - need] = i;
    }
    build_good(a);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}