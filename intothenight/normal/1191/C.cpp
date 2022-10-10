#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, k;
	cin >> n >> m >> k;
	deque<ll> q(m);
	for(auto &x: q){
		cin >> x;
		x --;
	}
	ll res = 0, cnt = 0;
	while(!q.empty()){
		res ++;
		ll p = (q.front() - cnt) / k;
		auto x = lower_bound(q.begin(), q.end(), k * (p + 1) + cnt);
		if(x == q.end()){
			break;
		}
		ll val = *x;
		while(q.front() != val){
			q.pop_front();
			cnt ++;
		}
	}
	cout << res;
	return 0;
}