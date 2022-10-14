#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
int n, k;
vector<pair<int, int>> z;
map<int, int> cnt;
bool can(int x) {
	int cn = 0;
	for(auto i : z)
		cn += i.second/x;
	return cn>=k;
}
void cut(int x) {
	for(auto i : z)while(i.second>=x){cout << i.first << " ", i.second-=x, k--;if(!k) exit(0);}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		cnt[t]++;
	}
	for(auto i : cnt)
		z.pb(i);
	int ans = 0;
	for(int i = 1<<16; i; i>>=1)if(can(ans+i))ans+=i;
	cut(ans);
}