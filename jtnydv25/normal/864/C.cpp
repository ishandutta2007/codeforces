#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> vec;
int main(){
	ll a, b, f, k;
	cin >> a >> b >> f >> k;
	// cerr << b << " " << f << endl;
	if(b < f){
		cout << -1;
		return 0;
	}
	if(k > 1 && b < 2 * (a - f)){
		cout << -1;
		return 0;
	}

	vec = {k * a};

	for(int i = 0; 2 * i + 1 <= k; i++){
		vec.push_back(2 * i * a + f);
	}

	for(int i = 1; 2 * i <= k; i++){
		vec.push_back(2 * i * a - f);
	}
	sort(vec.begin(), vec.end());

	int n = vec.size();

	ll curr = b, lst = 0, nxt;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ll dist = vec[i] - lst;
		if(i < n - 1) nxt = vec[i + 1] - vec[i];
		curr -= dist;
		if(curr < 0){
			cout << -1;
			return 0;
		}

		if(i < n - 1 && curr < nxt){
			ans++;
			curr = b;
		}
		lst = vec[i];
	}
	cout << ans;
}