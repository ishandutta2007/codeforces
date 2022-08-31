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
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		lint ret = 0;
		for(int i=2; i<=n; i++){
			if(a[i-1] > a[i]) ret -= a[i] - a[i-1];
		}
		printf("%lld\n", ret);
	}
}