#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k;
int ans[1000][1000];
int max1 = 0;
void solve(int l, int r, int now) {
	if(l == r) {
		return;
	}
	max1 = max(max1, now);
	if(r - l + 1 <= k) {
		for(int i = l; i <= r; i++) {
			for(int j = i + 1; j <= r; j++) {
				ans[i][j] = now;
			}
		}
		return;
	}
	int len1 = (r - l + 1) / k;
	int len2 = (r - l) / k + 1;
	int am = (r - l + 1) - len1 * k;
	int prev = l;
	vi group(r - l + 1);
	for(int i = 0; i < k; i++) {
		if(i < am) {
			solve(prev, prev + len2 - 1, now + 1);
			for(int j = prev; j < prev + len2; j++) {
				group[j - l] = i;
			}
			prev += len2;
		} else {
			solve(prev, prev + len1 - 1, now + 1);
			for(int j = prev; j < prev + len1; j++) {
				group[j - l] = i;
			}
			prev += len1;
		}
	}
	for(int i = l; i <= r; i++) {
		for(int j = i + 1; j <= r; j++) {
			if(group[i - l] != group[j - l]) {
				ans[i][j] = now;
			}
		}
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
    cin >> n >> k;
    solve(0, n - 1, 1);
    cout << max1 << '\n';
    for(int i = 0; i < n; i++) {
    	for(int j = i + 1; j < n; j++) {
    		cout << ans[i][j] << ' ';
    	}
    }
}