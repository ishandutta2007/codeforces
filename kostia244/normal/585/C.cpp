#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll a, b;
string s;
ll cnt = 0;
char p = '0';
void search(pi cur) {
	if(cur.first == 1 && cur.second == 1) {
		return;
	}
//	cout << cur.first << " " << cur.second << "\n";
//	if(s.size()>2) return;
	if(cur.first > cur.second) {
		ll t = cur.first/cur.second;
		if(cur.first%cur.second==0)
			t--;
//		cout << cur.first << " " << cur.second << " " << t<< "\n";
		if(p=='A') cnt+=t;
		else {
			if(cnt) cout << cnt << p;
			cnt = t;
		}
		p='A';
//		cout << r.first+cur.first << " " << r.second+cur.second << "\n";
		search({cur.first-t*cur.second, cur.second});
	} else {
		ll t = cur.second/cur.first;
		if(cur.second%cur.first==0)
			t--;
//		cout << cur.first << " " << cur.second << " " << t<< "\n";
		if(p=='B') cnt+=t;
		else {
			if(cnt) cout << cnt << p;
			cnt = t;
		}
		p = 'B';
//		cout << l.first+cur.first << " " << l.second+cur.second << "\n";
		search({cur.first, cur.second-t*cur.first});
	}
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	if(__gcd(a, b)>1) return cout << "Impossible",0;//numb brick lol
	search({a, b});
	if(cnt) cout << cnt << p;
}