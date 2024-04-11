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
string s;
int main() {
	cin >> n;
	while(n--)
		cin >> t, s += ('0'+t);
	s += s;
	for(auto& i : s) {
		if(i == '0') k = 0;
		else k++;
		ans = max(ans, k);
	}
	cout << ans;
}