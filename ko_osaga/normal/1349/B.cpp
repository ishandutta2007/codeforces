#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 200005;

int tc, n, a[MAXN], k;
int b[MAXN];

int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i]);
		}
		if(count(a + 1, a + n + 1, k) == 0){
			puts("no");
			continue;
		}
		bool good = n == 1;
		for(int i=1; i<=n; i++){
			b[i] = (a[i] >= k);
		}
		for(int i=2; i<=n; i++){
			if(b[i] && b[i-1]){
				good = 1;
				break;
			}
		}
		for(int i=3; i<=n; i++){
			if(b[i-2] && b[i]){
				good = 1;
				break;
			}
		}
		puts(good ? "yes" : "no");
	}
}