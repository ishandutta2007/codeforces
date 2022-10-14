#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
int n, t;
vi v;

int main() {
	cin >> n;
	while(n--) {
		cin >> t;
		auto i = upper_bound(all(v), t-1);
		if(i == v.end()) v.pb(t);
		else *i = t;
	}
	cout << v.size();
}