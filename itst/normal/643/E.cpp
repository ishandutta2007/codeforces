#include<bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define ld long double
const int _ = 5e5 + 7; vector < ld > dp[_]; int Q , cnt , fa[_];

int main(){
	ios::sync_with_stdio(0); int tp , x; dp[cnt = 1].push_back(1);
	for(cin >> Q ; Q ; --Q){
		cin >> tp >> x;
		if(tp == 1){
			dp[++cnt].push_back(1); ld preval = 0; int cur = cnt , pre = cnt , dst = 0; fa[cnt] = x;
			while(dp[cur][dst] > eps && (cur = fa[cur])){
				if(dp[cur].size() == ++dst) dp[cur].push_back(0);
				ld t = dp[cur][dst];
				dp[cur][dst] = 1 - (1 - dp[cur][dst]) / (1 - 0.5 * preval) * (1 - 0.5 * dp[pre][dst - 1]);
				pre = cur; preval = t;
			}
		}else{
			ld sum = -1; for(auto t : dp[x]) sum += t;
			cout << fixed << setprecision(9) << sum << '\n';
		}
	}
	return 0;
}