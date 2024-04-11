#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 3005;
pi a[MAXN];

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		a[i].second = i;
		for(int j=0; j<4; j++){
			int x; cin >> x; a[i].first += x;
		}
	}
	sort(a, a+n, [&](const pi &a, const pi &b){
		return pi(-a.first, a.second) < pi(-b.first, b.second);
	});
	for(int i=0; i<n; i++){
		if(a[i].second == 0){
			cout << i+1 << endl;
			return 0;
		}
	}
}