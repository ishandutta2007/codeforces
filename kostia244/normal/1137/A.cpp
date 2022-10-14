//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
int n, m, mat[1010][1010], r[1010][1010], c[1010][1010], ra[1010], ca[1010], v[1010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
//	n=m=1000;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) //mat[i][j] = i+j;
			cin >> mat[i][j];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			v[j] = mat[i][j];
		}
		sort(v, v+m);
		int e = unique(v, v+m)-v;
		ra[i] = e;
		for(int j = 0; j < m; j++) {
			r[i][j] = lower_bound(v, v+e, mat[i][j])-v+1;
		}
	}
	for(int j = 0; j < m; j++)  {
		for(int i = 0; i < n; i++){
			v[i] = mat[i][j];
		}
		sort(v, v+n);
		int e = unique(v, v+n)-v;
		ca[j] = e;
		for(int i = 0; i < n; i++){
			c[i][j] = lower_bound(v, v+e, mat[i][j])-v+1;
		}
	}
	for(int i = 0; i < n; i++, cout << "\n") {
		for(int j = 0; j < m; j++) {
//			ll up = max(r[i][j], c[i][j]);
			if(c[i][j]<r[i][j]) {
				cout << max(ra[i], ca[j] +abs(c[i][j]-r[i][j])) << " ";
			} else
				cout << max(ca[j], ra[i] +abs(c[i][j]-r[i][j])) << " ";
//			cout << ca[i] << " " << r[i][j] << "\n";
		}
	}
}