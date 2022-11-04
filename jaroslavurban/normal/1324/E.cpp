#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use generate(all(vec), nxt) for filling a vector with function calls
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// vec to a set -> use "set s(all(vec));"
// is key in a set/map? use s.count(key)
// ll pos = partition_point(all(vec), p) - vec.begin();
// print number in binary -> cout << bitset<20>(n);
// use min({a, b, c})
ll nxt() {ll x; cin >> x; return x;}

ll dp[2000][2000]; // time, i
ll arr[2000];
ll n, h, l, r;

ll findOpt(ll t, ll i){
	if (i == n) return 0;
	if (dp[t][i] != -1) return dp[t][i];
	ll t1 = (arr[i] + t - 1) % h;
	ll t2 = (arr[i] + t) % h;
	ll r1 = findOpt(t1, i+1) + (t1 >= l && t1 <= r);
	ll r2 = findOpt(t2, i+1) + (t2 >= l && t2 <= r);
	dp[t][i] = max(r1, r2);
	return dp[t][i];
}


int main(){
	n = nxt();
	h = nxt();
	l = nxt();
	r = nxt();
	generate(arr, arr + n, nxt);
	fill(&dp[0][0], &dp[0][0] + 2000*2000, -1);
	cout << findOpt(0, 0) << endl;
}