#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k;
int loc = 0;
set<int> V;
int dist(int i) {
	auto it = V.upper_bound(i);
	int ans = 1<<20;
	if(it!=V.end()) ans = min(ans, abs(i-*it));
	if(it!=V.begin()) ans = min(ans, abs(i-*--it));
	return ans;
}
int realq(int i, int j) {
	return dist(i)<=dist(j);
}
bool q(int i, int j) {
	cout << "1 " << i << " " << j << endl;
	cout.flush();
	if(loc)
	return realq(i, j);
	string t;
	cin >> t;
	return t=="TAK";
}
int x = -1;
int find(int l, int r, int bias = 0) {
	if(l==r) {
		if(x!=-1&&!q(l, x)) {
			return -1;
		}
		return l;
	}
	int mid = bias?bias:(l+r)/2;
	return q(mid, mid+1)?find(l, mid):find(mid+1, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	if(loc) {
	V.insert(2);
	V.insert(3);
	n=3, k = 2;
	} else {
	cin >> n >> k;
	}
	set<int> a;
	x = find(1, n);
	a.insert(x);
	if(x>1)
	a.insert(find(1, x-1));
	if(x<n)
	a.insert(find(x+1, n));
	if(a.count(-1)) a.erase(-1);
	while(a.size()>2) a.erase(a.begin());
	cout << "2 ";
	cout << *a.begin() << " ";
	cout << *++a.begin();
	cout << endl;
//	ios::eof(stdin);
	cout.flush();
	return 0;
}