#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 540000;
int nxt[maxn], p[maxn];
vector<int> G[maxn];
void solve(int L, int R, int l, int r){
	//cout << L << " " << R << " " << l << " " << r << endl;
	if(L > R) return;
	p[R] = r;
	if(L == R) return;
	if(G[R].size() == 0){
		solve(L, R - 1, l, r - 1);
		return;
	}
	else{
		int rr = r - 1;
		for(int i = 0; i <= (int)G[R].size(); i += 1){
			if(i == 0){
				int m = max(G[R][0] - L + 1, 0);
				solve(L, G[R][0], rr - m + 1, rr);
				rr -= m;
			}
			else if(i < (int)G[R].size()){
				int m = max(G[R][i] - G[R][i - 1], 0);
				solve(G[R][i - 1] + 1, G[R][i], rr - m + 1, rr);
				rr -= m;
			}
			else{
				int m = max(R - 1 - G[R][i - 1], 0);
				solve(G[R][i - 1] + 1, R - 1, rr - m + 1, rr);
			}
		}
	}
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1; i += 1) G[i].clear();
	for(int i = 1; i <= n; i += 1) cin >> nxt[i];
	nxt[n + 1] = -1;
	stack<int> s;
	for(int i = 1; i <= n; i += 1) if(~nxt[i]) G[nxt[i]].push_back(i);
	for(int i = 1; i <= n + 1; i += 1){
		for(int j = (int)G[i].size() - 1; ~j; j -= 1)
			if(s.empty() or s.top() != G[i][j]){
				cout << "-1\n";
				return;
			}
			else s.pop();
		if(~nxt[i]) s.push(i);
	}
	solve(1, n + 1, 1, n + 1);
	for(int i = 1; i <= n; i += 1) cout << p[i] << " ";
	cout << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	for(cin >> t; t; t -= 1){
		solve();
		//cout << endl;
	}
	return 0;
}