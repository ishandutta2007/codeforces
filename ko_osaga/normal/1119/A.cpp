#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;
using lint = long long;

int n;
int l[MAXN], r[MAXN];

int main(){
	scanf("%d",&n);
	memset(l, 0x3f, sizeof(l));
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x);
		l[x] = min(l[x], i);
		r[x] = max(r[x], i);
	}
	vector<pi> v;
	for(int i=1; i<=n; i++){
		if(l[i] <= n) v.emplace_back(l[i], i);
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<2; j++){
			if(v[j].second != i){
				ret = max(ret, r[i] - v[j].first);
			}
		}
	}
	cout << ret << endl;
}