#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e6 + 5;
ll n, a, b, ca = -1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >> a >> b;
	for(int i = 0; i*a <= n; i++) {
		if((n-i*a)%b==0) ca = i;
	}
	if(ca == -1) return cout << -1, 0;
	int cnt = 1;
	while(n%b) {
		cout << cnt + a -1 << " ";
		for(int i = cnt; i < cnt + a -1; i++)
			cout << i << " ";
		n -= a;
		cnt += a;
	}
	while(n) {
		cout << cnt + b -1 << " ";
		for(int i = cnt; i < cnt + b -1; i++)
			cout << i << " ";
		n -= b;
		cnt += b;
	}
}