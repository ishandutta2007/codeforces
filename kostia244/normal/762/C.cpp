//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 455;
string a, b;
int x[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	pair<int, int> ans = {1<<20, -1};
	for(int j = a.size(), i = b.size()-1; i>=0;i--) {
		j--;
		while(j >= 0 && a[j]!=b[i]) j--;
		x[i] = j;
		if(j>-1)
		ans = min(ans, {i, -1});
	}
//	cout << ans.first << "\n";
//	for(int i = 0; i < b.size(); i++)
//		cout << x[i] << " ";
//	cout << '\n';
	for(int j = -1, i = 0; i < b.size(); i++) {
		j=min(j+1, (int)a.size());
		while(j < a.size() && a[j]!=b[i]) j++;
		int p = i;
		for(int i = 1<<17; i>>=1;)
			if(p+i<b.size()&&x[p+i]<=j) p+=i;
		p++;
//		cout << i << " "<< j << " " << p << "\n";
		if(j!=a.size()) {
//			cout << i << " " << p << "\n";
			ans = min(ans, {p-i-1, i});
		}
	}
//	cout << ans.first << " " << ans.second << "r\n";
	if(ans.first>=(int)b.size()) cout << "-";
	else cout << b.substr(0, ans.second+1) << b.substr(ans.second+ans.first+1);
}