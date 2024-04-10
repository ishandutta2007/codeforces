#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll q, n, m;

bool isval(ll t){
	ll cnt = 0, sum = 0, c = 1, i = 0;
	while(sum <= m * t){
		if(i > t){
			return 0;
		}
		if(sum + i * c <= m * t){
			sum += i * c;
			cnt += c;
		}
		else{
			cnt += (m * t - sum) / i;
			sum = m * t + 1;
		}
		if(cnt >= n){
			return 1;
		}
		i++;
		c = c * (t - i + 1) / i;
	}
	return (cnt >= n);
}

int main(){
	
	cin >> q;
	
	while(q--){
		cin >> n >> m;
		ll l = -1, r = n, mid;
		while(r - l > 1){
			mid = (l + r) / 2;
			if(isval(mid)){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		cout << r << endl;
	}
	
	return 0;
}