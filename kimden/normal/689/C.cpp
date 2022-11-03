#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(ll n){
	ll i=2;
	ll ans=0;
	while(n>=i*i*i){
		ans += n/(i*i*i);
		i++;
	}
	return ans;
}

int main()
{
	ll m;
	cin >> m;
	ll left,right,mid;
	ll res,best;
	right = 8*m+8;
	left = 4*m;
	best = sum(right);
	while(right-left>1){
		mid = left + (right-left)/2;
		res = sum(mid);
		if(res<m){
			left = mid;
		}else{
			right = mid;
			best = res;
		}
	}
	//res = sum(right);
	if(best>m){
		cout << -1;
		return 0;
	}else{
		cout << right;
	}
}