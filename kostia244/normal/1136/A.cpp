#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define maxn 300005
#define mod 1000000007ll
using namespace std;

int n, k;
__V<pi> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
v.resize(n);
for(auto& i : v) cin >> i.first >> i.second;
	int i = 0;
	cin >> k;
	while(i < n && k > v[i].second) i++;
	cout << (n-i);
	return 0;
}