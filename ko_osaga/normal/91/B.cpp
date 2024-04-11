#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[100005];
int ans[100005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	vector<pi> v;
	memset(ans, -1, sizeof(ans));
	for(int i=n-1; i>=0; i--){
		auto l = lower_bound(v.begin(), v.end(), pi(-a[i], 1e9));
		if(l != v.end()) ans[i] = l->second;
		if(v.empty() || -v.back().first > a[i]){
			v.push_back(pi(-a[i], i));
		}
	}
	for(int i=0; i<n; i++){
		if(ans[i] == -1) printf("-1 ");
		else printf("%d ", ans[i] - i - 1);
	}
}