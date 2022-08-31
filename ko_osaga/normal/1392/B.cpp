#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n, a[MAXN];

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		lint k;
		scanf("%d %lld",&n,&k);
		if(k > 4){
			lint q = k / 2 - 2;
			k -= q * 2;
		}
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		while(k--){
			int mx = *max_element(a + 1, a + n + 1);
			for(int i=1; i<=n; i++) a[i] = mx - a[i];
		}
		for(int i=1; i<=n; i++) printf("%d ", a[i]);
		puts("");
	}
}