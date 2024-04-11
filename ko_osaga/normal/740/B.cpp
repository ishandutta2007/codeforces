#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, lint> pi;

int n, m, a[105];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	int ret = 0;
	while(m--){
		int s, e;
		cin >> s >> e;
		ret += max(a[e] - a[s-1], 0);
	}
	cout << ret;
}