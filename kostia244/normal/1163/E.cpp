//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;
int n;
vi a;

vi basis;
void insert(int x) {
	for(auto i : basis)
		x = min(x, x^i);
	if(x)
	basis.pb(x);
}
bool check(int x) {
	for(auto i : basis)
		x = min(x, x^i);
	return x==0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	vi ans = {0};
	int pos = 0;
	for(int i = 0; i <= 20 && pos < a.size(); i++) {
		for(int k = 1<<i; k--;)
			ans.pb(ans[k]);
		while(pos<a.size()&&check(a[pos])) pos++;
		if(pos==a.size()) break;
//		cout << pos << " " << a[pos] << "pos\n";
		for(int j = 1<<i; j < 1<<(i+1); j++) {
			ans[j]^=a[pos];
		}
		insert(a[pos++]);
	}
	set<int> x;
	int rr = 0;
	for(int i = 0; i < ans.size(); i++) {
		if(!x.insert(ans[i]).second) break;
		if(*x.rbegin()+1 == x.size()&& (i&(i+1))==0) {
//			cout << (*x.rbegin()) << " " << x.size() << "\n";
			rr = i+1;
		}
	}
	cout << __lg(rr) << "\n";
	for(int i = 0; i < rr; i++)
		cout << ans[i] << " ";
}