#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 800005;
const int mod = 1e9 + 7;

int main(){
	int tc;
	scanf("%d",&tc);
	for(int i = 0; i < tc; i++){
		int n; scanf("%d",&n);
		vector<int> a(n);
		for(int j = 0; j < n; j++) scanf("%d",&a[j]);
		sort(all(a));
		lint ret = 0;
		for(int i = 1; i < n; i++){
			int l = i, r = n - i;
			ret += (1ll * l * r - 1) * (a[i] - a[i-1]);
		}
		printf("%lld\n", -ret);
	}
}