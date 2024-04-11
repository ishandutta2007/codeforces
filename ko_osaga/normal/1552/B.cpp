#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int k, n, a[10][MAXN];
int p[MAXN];

bool cmp(int x, int y){
	int cnt = 0;
	for(int i=0; i<k; i++){
		if(a[i][x] < a[i][y]) cnt++;
		else cnt--;
	}
	return cnt > 0;
}

void solve(int l, int r){
	if(l == r) return;
	int m = (l + r) / 2;
	solve(l, m); solve(m + 1, r);
	int p1 = l, p2 = m + 1;
	vector<int> dap;
	while(p1 < m+1 && p2 < r+1){
		if(cmp(p[p1], p[p2])){
			dap.push_back(p[p1++]);
		}
		else dap.push_back(p[p2++]);
	}
	while(p1 < m+1) dap.push_back(p[p1++]);
	while(p2 < r+1) dap.push_back(p[p2++]);
	for(int i=l; i<=r; i++) p[i] = dap[i - l];
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k = 5;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 5; j++){
				scanf("%d",&a[j][i]);
			}
		}
		iota(p, p + n, 1);
		solve(0, n - 1);
		int ans = p[0];
		for(int i = 1; i < n; i++){
			if(!cmp(p[0], p[i])) ans = -1;
		}
		cout << ans << endl;
	}
}