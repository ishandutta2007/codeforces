#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, l, r, now, last, then;
vector<pair<ll, bool> > v;
vector<pll> ans;

int main(){
	fast_io;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l, &r);
		v.pb({l, 0});
		v.pb({r, 1});
	}
	sort(v.begin(), v.end());
	for(ll i = 0; i < v.size(); i++){
		then = now;
		if(!v[i].S){
			now++;
		}
		else{
			now--;
		}
		if(then < k && now >= k){
			last = i;
		}
		if(then >= k && now < k){
			if(!ans.empty()){
				if(ans.back().S == v[last].F){
					ans.back().S = v[i].F;
				}
				else{
					ans.pb({v[last].F, v[i].F});
				}
			}
			else ans.pb({v[last].F, v[i].F});
		}
	}
	printf("%d \n", ans.size());
	for(ll i = 0; i < ans.size(); i++){
		printf("%d %d \n", ans[i].F, ans[i].S);
	}
	return 0;
}