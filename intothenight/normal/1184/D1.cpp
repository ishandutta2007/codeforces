#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m, t;
	cin >> n >> k >> m >> t;
	while(t --){
		int type, x;
		cin >> type >> x;
		if(type){
			n ++;
			if(x <= k){
				k ++;
			}
		}
		else{
			if(x < k){
				n -= x;
				k -= x;
			}
			else{
				n = x;
			}
		}
		cout << n << " " << k << "\n";
	}
	return 0;
}