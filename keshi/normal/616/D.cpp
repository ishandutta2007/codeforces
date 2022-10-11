#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, k, a[MAXN], l, r, t, l1, r1;

map<ll, ll> cnt;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	while(l < n && r < n){
		//cout << l << " " << r << endl;
		if(t == k && cnt[a[r]] == 0){
			cnt[a[l]]--;
			if(cnt[a[l]] == 0){
				t--;
			}
			l++;
			r--;
		}
		else{
			if(r - l > r1 - l1){
				l1 = l;
				r1 = r;
			}
			if(cnt[a[r]] == 0){
				t++;
			}
			cnt[a[r]]++;
		}
		r++;
	}
	
	cout << l1 + 1 << " " << r1 + 1;
	
	return 0;
}