#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3000005;

vector<int> v[2], ev;
bool trk[MAXN][2];
int dp[MAXN][2];
int n, t;

bool Has(int y, int x){
	return binary_search(v[x].begin(), v[x].end(), y);
}

bool findCut(){
	for(auto &i : v[0]){
		ev.push_back(i);
		ev.push_back(i + 1);
	}
	for(auto &i : v[1]){
		ev.push_back(i);
		ev.push_back(i + 1);
	}
	ev.push_back(0);
	sort(ev.begin(), ev.end());
	ev.resize(unique(ev.begin(), ev.end()) - ev.begin());
	dp[0][1] = -2e9;
	for(int i=1; i<ev.size(); i++){
		for(int j=0; j<2; j++){
			if(!Has(ev[i - 1], j) && dp[i-1][j] < min(dp[i-1][j^1], t)){
				dp[i][j] = min(dp[i-1][j^1], t) + ev[i] - ev[i-1];
				trk[i][j] = 1;
			}
			else{
				dp[i][j] = dp[i-1][j] + ev[i] - ev[i-1];
			}
			if(Has(ev[i], j)){
				dp[i][j] -= t;
				if(dp[i][j] <= 0) dp[i][j] = -2e9;
			}
		}
	}
	return max(dp[ev.size() - 1][0], dp[ev.size() - 1][1]) >= 0;
}

void trace(){
	int pos = 0;
	if(dp[ev.size() - 1][0] < 0) pos = 1;
	vector<pi> boom;
	vector<int> trans;
	for(int i=ev.size() - 1; i; i--){
		if(Has(ev[i], pos)){
			int where = ev[i] - dp[i][pos];
			where = max(where, 1);
			boom.emplace_back(where, pos + 1);
			dp[i][pos] += t;
		}
		if(trk[i][pos]){
			pos ^= 1;
			trans.push_back(ev[i - 1]);
		}
	}
	assert(pos == 0);
	reverse(trans.begin(), trans.end());
	reverse(boom.begin(), boom.end());
	cout << trans.size() << endl;
	for(auto &i : trans) printf("%d ", i);
	cout << endl <<  boom.size() << endl;
	for(auto &i : boom) printf("%d %d\n", i.first, i.second);
}

int main(){
	int t0, t1;
	scanf("%d %d %d %d",&n,&t0,&t1,&t);
	v[0].resize(t0);
	v[1].resize(t1);
	for(int i=0; i<2; i++){
		for(auto &j : v[i]){
			scanf("%d",&j);
		}
	}
	if(!findCut()){
		puts("No");
		return 0;
	}
	puts("Yes");
	trace();
}