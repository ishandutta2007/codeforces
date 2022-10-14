#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
char r[2][202020];
int lst[2][202020], T = 0;
void solve() {
	int n;
	cin >> n;
	for(int a= 0; a < 2; a++)
		for(int i = 0; i < n; i++)
			cin >> r[a][i];
	int p = 0;
	for(int i = 0; i < n; i++) {
		if(r[p][i] > '2') {
			if(r[p^1][i] < '3')
			{cout << "NO\n";return;}
			p^=1;
		}
//		cout << p << " ";
	}
	cout << (p!=1 ? "NO" : "YES") << "\n";
}
int main() {
	memset(lst, 0, sizeof lst);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--) solve();
}