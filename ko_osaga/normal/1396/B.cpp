#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;

int n;
lint a[MAXN];

int main(){
	int t; cin >> t;
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
		lint sum = accumulate(a, a + n + 1, 0ll);
		lint mx = *max_element(a + 1, a + n + 1);
		if(mx * 2 > sum){
			puts("T");
		}
		else{
			if(sum % 2) puts("T");
			else puts("HL");
		}
	}
}