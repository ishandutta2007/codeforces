#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119 * (1 << 23) + 1);
string t, cur = "/";

void parse(string& x) {
	x+='/';
	vector<string> a;
	string s;
	for(int i = 1; i < x.size(); i++) {
		if(x[i]!='/') {
			s+=x[i];
			continue;
		}
		if(s=="..")
			a.pop_back();
		else
			a.push_back(s);
		s="";

	}
	x="/";
	for(auto i : a)
		x+=i+'/';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, ans = 1;
	cin >> n;
	while(n--) {
		cin >> t;
		if(t == "pwd")
			cout << cur << "\n";
		else {
			cin >> t;
			if(t[0] != '/') t = cur+t;
			parse(t);
			cur = t;
		}
	}
}