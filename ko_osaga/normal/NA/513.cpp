#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 5005;

int n;
pi a[MAXN];

int main(){
	cin >> n;
	for(int i=1; i<=2*n; i++){
		int x; cin >> x;
		if(a[x].first) a[x].second = i;
		else a[x].first = i;
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			auto l = a[i], r = a[j];
			if(l > r) swap(l, r);
			if(r.first < l.second) cnt++;
			if(r.second < l.second) cnt++;
		}
	}
	cout << cnt << endl;
}