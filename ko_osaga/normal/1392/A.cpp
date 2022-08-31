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
		int c = count(a + 1, a + n + 1, a[1]);
		if(c == n) printf("%d\n", n);
		else printf("%d\n", 1);
	}
}