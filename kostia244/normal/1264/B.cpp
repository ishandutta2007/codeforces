#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
bool solve(int a, int b, int c, int d, int x) {
	vi l = {a, b, c, d};
	vi ans;
	for(int i = 0; i < a+b+c+d; i++) {
		if((i&1)==x) {
			if(l[0]) ans.pb(0), l[0]--;
			else ans.pb(2), l[2]--;
		} else {
			if(l[1]) ans.pb(1), l[1]--;
			else ans.pb(3), l[3]--;
		}
	}
	for(int i = 0; i < 4; i++) if(l[i] < 0) return 0;
	for(int i = 1; i < ans.size(); i++) {
		if(abs(ans[i]-ans[i-1])!=1) return 0;
	}
	cout << "YES\n";
	for(auto i : ans) cout << i << " ";
	exit(0);
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	solve(a, b, c, d, 1);
	solve(a, b, c, d, 0);
	cout << "NO\n";
}