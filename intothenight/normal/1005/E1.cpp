#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	int pos;
	for(int i = 0; i < n; i ++){
		cin >> p[i];
		if(p[i] == m){
			pos = i;
		}
	}
	vector<ll> left(2 * n + 1), right(2 * n + 1);
	int val = 0;
	left[n] = right[n] = 1;
	for(int i = pos - 1; i >= 0; i --){
		if(p[i] > m){
			val ++;
			left[val + n] ++;
		}
		else{
			val --;
			left[val + n] ++;
		}
	}
	val = 0;
	for(int i = pos + 1; i < n; i ++){
		if(p[i] > m){
			val --;
			right[val + n] ++;
		}
		else{
			val ++;
			right[val + n] ++;
		}
	}
	ll res = 0;
	for(int i = 0; i <= 2 * n; i ++){
		res += left[i] * right[i];
	}
	for(int i = 0; i < 2 * n; i ++){
		res += left[i + 1] * right[i];
	}
	cout << res;
	return 0;
}