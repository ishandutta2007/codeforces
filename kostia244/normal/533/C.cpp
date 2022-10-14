#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
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
const int maxn = 3e5 + 5;
int col[400], dist[400], a[maxn], n, k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	if(x+y<=max(a, b)) return cout << "Polycarp", 0;
	cout << (((!(a<x||b<y))&&(a>x||b>y))?"Polycarp":"Vasiliy");
}