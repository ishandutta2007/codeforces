#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 4005;

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		int n; scanf("%d",&n);
		vector<int> cnt(30);
		for(int i = 0; i < n; i++){
			int x; scanf("%d",&x);
			for(int j = 0; j < 30; j++){
				if((x >> j) & 1) cnt[j]++;
			}
		}
		int g = 0;
		for(int i = 0; i < 30; i++){
			g = gcd(g, cnt[i]);
		}
		if(g == 0){
			for(int i = 1; i <= n; i++) printf("%d ", i);
		}
		else{
			for(int i = 1; i <= n; i++) if(g % i == 0) printf("%d ", i);
		}
		puts("");
	}
}