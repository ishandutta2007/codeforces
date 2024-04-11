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

int n, m, ans;

int main() {
	cin >> n >> m;
	if(m%n)
		return cout << -1, 0;
	m = m/n;
	while(m%3 == 0) m/=3, ans++;
	while(m%2 == 0) m/=2, ans++;
	if(m == 1)
		cout << ans;
	else
		cout << -1;
}