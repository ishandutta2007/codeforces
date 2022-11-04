#include<bits/stdc++.h>
#define INF 1000000000
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
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	vi small(n);
	vi big(n);
	vi st;
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[i] >= a[st[st.size() - 1]]) {
			if(st.size() == 1) {
				big[st[st.size() - 1]] = n;
			} else {
				big[st[st.size() - 1]] = st[st.size() - 2];
			}
			st.pop_back();
		}
		st.push_back(i);
	}
	while(!st.empty()) {
		if(st.size() == 1) {
			big[st[st.size() - 1]] = n;
		} else {
			big[st[st.size() - 1]] = st[st.size() - 2];
		}
		st.pop_back();
	}
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[i] <= a[st[st.size() - 1]]) {
			if(st.size() == 1) {
				small[st[st.size() - 1]] = n;
			} else {
				small[st[st.size() - 1]] = st[st.size() - 2];
			}
			st.pop_back();
		}
		st.push_back(i);
	}
	while(!st.empty()) {
		if(st.size() == 1) {
			small[st[st.size() - 1]] = n;
		} else {
			small[st[st.size() - 1]] = st[st.size() - 2];
		}
		st.pop_back();
	}
	vi ans(n, INF);
	ans[0] = 0;
	for(int i = 0; i < n - 1; i++) {
		if(ans[i] == INF) {
			continue;
		}
		ans[i + 1] = min(ans[i + 1], ans[i] + 1);
		int now = i + 1;
		if(a[i] < a[i + 1]) {
			while(now < n) {
				ans[now] = min(ans[now], ans[i] + 1);
				if(a[now] <= a[i]) {
					break;
				}
				now = small[now];
			}
		} else if(a[i] > a[i + 1]) {
			while(now < n) {
				ans[now] = min(ans[now], ans[i] + 1);
				if(a[now] >= a[i]) {
					break;
				}
				now = big[now];
			}
		}
	}
	cout << ans[n - 1];	
}