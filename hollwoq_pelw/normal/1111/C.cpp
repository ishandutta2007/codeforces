#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

int n, k, a, b;

ll dfs(int l, int r, vector<int> &c) {
	if(!c.size()) {
		return a;
	}
	ll a1=(ll)b*(r-l+1)*c.size();
	if(l<r) {
		int m=(l+r)/2;
		vector<int> d, e;
		for(int ci : c) {
			if(ci<=m)
				d.push_back(ci);
			else
				e.push_back(ci);
		}
		a1=min(dfs(l, m, d)+dfs(m+1, r, e), a1);
	}
	return a1;
}

int main()
{
	IOS;
	cin >> n >> k >> a >> b;
	vector<int> c(k);
	for(int i=0; i<k; ++i)
		cin >> c[i], --c[i];
	cout << dfs(0, (1<<n)-1, c);
	return 0;
}