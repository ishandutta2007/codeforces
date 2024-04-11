//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vi a;
	for(int i = 0; i < n; i++) {
		int t= s[i]=='(';
		if(a.empty()||(a.back()==t||t==1)) a.pb(t);
		else a.pop_back();
	}
	int ok = a.empty()||(a.size()==2&&a[0]==0&&a[1]==1);
	cout << (ok?"YES":"NO");
}