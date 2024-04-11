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
int n, k;
string s, t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++)
		t.pb(s[i%k]);
	if(t<s) {
		reverse(all(s));
		int i = s.size()-k;
		s+="0";
		for(; i < s.size(); i++)
			if(s[i]!='9') {
				s[i]++;
				break;
			} else
				s[i] = '0';
		if(s.back()=='0') s.pop_back();
		reverse(all(s));
		t.clear();
		for(int i = 0; i < n; i++)
			t.pb(s[i%k]);
	}
	cout << t.size() << "\n";
	cout << t;
}