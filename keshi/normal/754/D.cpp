//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const int inf = 2e9 + 2;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

int n, k, oon, ans;
pair<pii, int> a[maxn];
set<pii> s;

int main(){
	fast_io;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S;
		a[i].S = i + 1;
	}
	sort(a, a + n);
	oon = -1;
	for(int i = 0; i < n; i++){
		s.insert(Mp(a[i].F.S, a[i].S));
		if(Sz(s) > k){
			s.erase(s.begin());
		}
		if(Sz(s) == k){
			if(ans < s.begin()->F - a[i].F.F + 1){
				ans = s.begin()->F - a[i].F.F + 1;
				oon = i;
			}
		}
	}
	if(oon == -1){
		cout << "0\n";
		for(int i = 1; i <= k; i++){
			cout << i << " ";
		}
		return 0;
	}
	s.clear();
	for(int i = 0; i < n; i++){
		s.insert(Mp(a[i].F.S, a[i].S));
		if(Sz(s) > k){
			s.erase(s.begin());
		}
		if(i == oon){
			cout << ans << "\n";
			for(auto j : s){
				cout << j.S << " ";
			}
		}
	}
	
	return 0;
}