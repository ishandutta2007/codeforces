#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 110;
bool use[N]; 
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int n, k; scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i ++) use[i] = 0;
		int c = 0;
		for(int i = 1; i <= n; i ++) {
			int x; scanf("%d", &x);
			if(!use[x]) {
				use[x] = 1; c ++;
			}
		}
		if(c > k) puts("-1");
		else {
			vector<int> d;
			for(int i = 1; i <= n; i ++) if(use[i]) d.push_back(i);
			for(int i = 1; i <= n; i ++) if(!use[i] && d.size() < k) d.push_back(i);
			printf("%d\n", k * n);
			for(int i = 1; i <= n; i ++)
				for(int v : d) printf("%d ", v);
			puts("");
		}
	}	
	return 0;
}