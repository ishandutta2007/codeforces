#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119*(1<<23) + 1);
int x[100100];
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	sort(x+1, x+1+n);
	int a = 1;
	for(int i = 1; i < n; i++)
		if(x[i+1]-x[i]==1){
			a++;break;}
	cout << a << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}