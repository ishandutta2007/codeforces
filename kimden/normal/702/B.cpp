#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1000;

int main()
{
	int n,a;
	cin >> n;
	map<ll,ll> mp;
	for(int i=0;i<n;i++){
		cin >> a;
		mp[a]++;
	}
	ll ans=0;
	ll dg = 1;
	for(int i=0;i<32;i++){
		for(auto j: mp){
			if(mp[dg-j.first] == 0){
				mp.erase(dg-j.first);
			}else{
				if(dg == 2*j.first){
					ans += j.second * (mp[dg-j.first]-1);
				}else{
					ans += j.second * mp[dg-j.first];
				}
			}
		}
		dg <<= 1;
	}
	ans >>= 1;
	cout << ans;
}