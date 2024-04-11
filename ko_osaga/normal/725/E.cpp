#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int cnt[200005];
vector<pi> useful;
int nxt[200005];

int c, n;
vector<int> just;

bool solve(int x, int denom){
	if(x == 0) return 1;
	if(denom == -1) return 0;
	while(x){
		int w = nxt[min(x, denom)];
		if(w == -1) break;
		int can = x / useful[w].first;
		can = min(can, useful[w].second);
		x -= can * useful[w].first;
		denom = useful[w].first - 1;
	}
	return x == 0;
}


int main(){
	cin >> c >> n;
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		just.push_back(x);
		cnt[x]++;
	}
	sort(just.begin(), just.end());
	just.push_back(1e9);
	for(int i=1; i<=c; i++){
		if(cnt[i]) useful.push_back(pi(i, cnt[i]));
	}
	nxt[0] = -1;
	for(int i=1; i<=c; i++){
		nxt[i] = upper_bound(useful.begin(), useful.end(), pi(i, 1e9)) - useful.begin() - 1;
	}
	int denom = n, ret = 1e9;
	vector<int> v;
	for(int cur = c; cur;){
		int it = upper_bound(just.begin(), just.end(), cur) - just.begin() - 1;
		it = min(it, denom - 1);
		v.push_back(just[it]);
		cur -= just[it];
		denom = it;
	}
	int cnt = 0, p = 0;
	for(int i=c-1; i; i--){
		while(p < v.size() && v[p] >= i){
			cnt += v[p++];
		}
		if(cnt + i <= c && !solve(c - cnt - i, i-1)){
			ret = i;
		}
	}
	if(ret > 1e8){
		puts("Greed is good");
		return 0;
	}
	cout << ret << endl;
}