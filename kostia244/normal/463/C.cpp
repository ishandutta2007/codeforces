#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define maxn 300005
#define mod 1000000007ll
using namespace std;
pi ans[2];
int n, t;
ll mat[2001][2001], dsum[4015], asum[4015], val[2];

void upd(int i, int j, ll s) {
	if(s >= val[(i+j)&1])
		val[(i+j)&1] = s, ans[(i+j)&1].first = i, ans[(i+j)&1].second = j;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> t, mat[i][j] = t, dsum[i+j] += t, asum[2001+i-j] += t;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			upd(i, j, dsum[i+j] + asum[2001+i-j] - mat[i][j]);
	cout << val[0]+val[1] << "\n";
	cout << ans[0].first+1 << "  " << ans[0].second+1 << "  " << ans[1].first+1 << "  " << ans[1].second+1;

}