//#pragma GCC optimize("trapv")
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
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e3 + 5;
int n, m, k;
vpi t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	t.resize(k);
	for(auto &i : t){
		cin >> i.first >> i.second;i.first = min(i.first-1, n-i.first), i.second = min(i.second-1, m-i.second);
//		cout << i.first << " " << i.second << "\n";
		if(min(i.first,i.second)<=4) return cout << "YES", 0;}
	cout << "NO";
}