#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, x[MAXN], dp[MAXN];

bool trial(int s){
	vector<int> stka, stkb;
	memset(dp, 0, sizeof(dp));
	dp[n+2] = 1;
	stka.push_back(n+2);
	stkb.push_back(n+2);
	int last = n+2;
	for(int i=n+1; i>=1; i--){
		while(!stka.empty() && x[stka.back()] <= x[i]) stka.pop_back();
		while(!stkb.empty() && x[stkb.back()] >= x[i]) stkb.pop_back();
		stka.push_back(i);
		stkb.push_back(i);
		if(abs(x[i] - x[i-1]) > s) continue;
		int bound = n + 10;
		int st = 0, ed = stka.size() - 1;
		while(st != ed){
			int m = (st + ed + 1) / 2;
			if(x[stka[m]] <= s + x[i-1]) ed = m-1;
			else st = m;
		}
		if(x[stka[st]] > s + x[i-1]) bound = min(bound, stka[st] - 1);
		st = 0, ed = stkb.size() - 1;
		while(st != ed){
			int m = (st + ed + 1) / 2;
			if(x[stkb[m]] >= -s + x[i-1]) ed = m-1;
			else st = m;
		}
		if(x[stkb[st]] < -s + x[i-1]) bound = min(bound, stkb[st] - 1);
		if(last <= bound + 1) dp[i] = 1;
		if(dp[i]) last = i;
	}
//	printf("\n%d : ", s);
//	for(int i=1; i<=n+2; i++) printf("%d", dp[i]);
	return dp[1];
}

int main(){
	cin >> n;
	for(int i=0; i<n+2; i++) scanf("%d",&x[i]);
	x[n+2] = x[n+1];
	int s = 0, e = 1e9;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m+1;
	}
	cout << s;
}