#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<19, maxa = 1e7 + 333, mod = 1e9 + 7;
int a[maxn][2], lp[maxa], hp[maxa];
void pre() {
	vector<int> pr;
	for(int i = 2; i < maxa; i++) {
		if(!lp[i]) lp[i] = hp[i] = i, pr.push_back(i);
		else { 
			hp[i] = hp[i/lp[i]];
		}
		for(int j = 0; j < pr.size() && pr[j]*i < maxa && pr[j] <= lp[i]; j++)
			lp[pr[j]*i] = pr[j];
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	pre();
	int n;
	cin >> n;
	memset(a, -1, sizeof a);
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		int x = lp[t], y = 1;
		while(t%x == 0) t/=x, y *= x;
		if(t != 1 && y != 1 && __gcd(y, t) == 1) a[i][0] = y, a[i][1] = t;
	}
	for(int i = 0; i < n; i++) cout << a[i][0] << " ";cout << '\n';
	for(int i = 0; i < n; i++) cout << a[i][1] << " ";cout << '\n';
	return 0;
}