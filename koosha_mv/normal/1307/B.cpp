#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define f(a, b, c, d) for (int a = b; a < c; a += d)
#define F(a, b, c, d) for (int a = b; a > c; a -= d)
#define ztoa greater<int>()
#define vec vector<int>
#define s sort
#define __ " "
using namespace std;
long long n,a[1000000],k, d, mx = 0,ans=0;
int main() {
	cin >> n;
	for (ll i = 0; i < n; i ++) {
		mx=0,ans=0;
		cin >> k >> d;
		for (ll j = 0; j < k; j ++) {
			cin >> a[j];
			mx = max (mx, a[j]);
			if (a[j] == d) {
				ans =1;
			}
		}
		if (ans == 1) {
			cout << ans << endl;
			continue;
		}
		else cout<<max(d/mx+(d%mx>0),1ll*2)<<endl;
	}
}