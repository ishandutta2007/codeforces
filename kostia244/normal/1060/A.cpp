#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119*(1<<23) + 1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, e = 0;
	string s;
	cin >> n >> s;
	for(auto i : s) e += (i=='8');
	int ans = 0;
	for(int i = 1; i <= e; i++)
		if((n-i)/10 >= i)
			ans = i;
	cout << ans;
}