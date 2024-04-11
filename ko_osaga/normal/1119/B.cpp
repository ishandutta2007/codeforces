#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;
using lint = long long;

int n, h, a[MAXN];

bool trial(int n){
	vector<int> v(a, a + n);
	sort(v.rbegin(), v.rend());
	int w = (n + 1) / 2;
	lint ret = 0;
	for(int i=0; i<w; i++){
		ret += v[2 * i];
	}
	return ret <= h;
}

int main(){
	cin >> n >> h;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=n; i>=0; i--){
		if(trial(i)){
			cout << i << endl;
			return 0;
		}
	}
}