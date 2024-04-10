#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



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
    multiset<int> s;
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	s.insert(a);
    }
    vi ans(n);
    int now = 0;
    while(!s.empty()) {
    	if(s.size() == 1) {
    		ans[now] = *(s.begin());
    		break;
    	}
    	ans[now] = *(s.rbegin());
    	s.erase(--s.end());
    	ans[n - 1 - now] = *(s.rbegin());
    	s.erase(--s.end());
    	++now;
    	if(s.empty()) {
    		break;
    	}
    	if(s.size() == 1) {
    		ans[now] = *(s.begin());
    		break;
    	}
    	ans[now] = *(s.begin());
    	s.erase(s.begin());
    	ans[n - 1 - now] = *(s.begin());
    	s.erase(s.begin());
    	++now;
    }
    int res = 0;
    for(int i = 1; i < n - 1; i++) {
    	if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
    		++res;
    	}

    }
    cout << res << '\n';
    for(int i = 0; i < n; i++) {
    	cout << ans[i] << ' ';
    }
}