#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long long ll;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 400005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char str[MAXN];
int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		int n, k;
		scanf("%d %d",&n,&k);
		scanf("%s", str);
		vector<int> dap(k);
		for(int i=0; i<n; i++){
			if(str[i] == '?') continue;
			dap[i % k] |= (1 << (str[i] - '0'));
		}
		if(count(all(dap), 3)) puts("NO");
		else{
			int x1 = count(all(dap), 1);
			int x2 = count(all(dap), 2);
			if(max(x1, x2) > k / 2) puts("NO");
			else puts("YES");
		}
	}
}