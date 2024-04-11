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
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n, t, ans = 0, k = 0;
vi v, d = {1};
int main() {
	cin >> n;
	v.resize(n);
	for(int i = 1; i < n; i++) cin >> v[i], v[i] += v[i - 1], d.pb(i+1);
	k = 1-*min_element(v.begin(), v.end());
	for(int i = 0; i < n; i++) v[i] += k;
	vi tv = v;
	sort(v.begin(), v.end());
	bool flag = true;
	for(int i = 0; i < n; i++) flag &= (i+1 == v[i]);
	if(flag)
		for(int i = 0; i < n; i++)cout <<  tv[i] << " ";
	else
		cout << -1;

}