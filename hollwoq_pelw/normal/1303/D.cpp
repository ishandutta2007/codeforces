#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
ll m, c[61];

void solve() {
	cin >> n >> m;
	memset(c, 0, sizeof(c));
	ll s=0;
	for(int i=0, a; i<m; ++i) {
		cin >> a;
		s+=a;
		++c[31-__builtin_clz(a)];
	}
	if(s<n) {
		cout << "-1\n";
		return;
	}
	int ans=0;
	for(int i=0; i<60; ++i) {
		if(n>>i&1) {
			if(!c[i]) {
				int j=i+1;
				while(!c[j]) ++j;
				--c[j];
				while(--j>=i) {
					++c[j];
					++ans;
				}
				++c[i];
			}
			--c[i];
		}
		c[i+1]+=c[i]/2;
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}