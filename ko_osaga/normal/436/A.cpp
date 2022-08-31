#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, x;
vector<pi> v[2];
int dp[2005][2005];

int main(){
	cin >> n >> x;
	for(int i=1; i<=n; i++){
		int t, h, m;
		cin >> t >> h >> m;
		v[t].push_back(pi(h, m));
	}
	for(int i=0; i<2; i++){
		sort(v[i].begin(), v[i].end());
	}
	int ret = 0;
	for(int cur = 0; cur <= 1; cur++){
		priority_queue<int> pq[2];
		int pnt[2] = {}, h = x, cnt = 0;
		for(int i=0; ; i++){
			while(pnt[cur] < v[cur].size() && v[cur][pnt[cur]].first <= h){
				pq[cur].push(v[cur][pnt[cur]].second);
				pnt[cur]++;
			}
			if(!pq[cur].empty()){
				h += pq[cur].top();
				pq[cur].pop();
				cnt++;
			}
			else break;
			while(pnt[1-cur] < v[1-cur].size() && v[1-cur][pnt[1-cur]].first <= h){
				pq[1-cur].push(v[1-cur][pnt[1-cur]].second);
				pnt[1-cur]++;
			}
			if(!pq[1-cur].empty()){
				h += pq[1-cur].top();
				pq[1-cur].pop();
				cnt++;
			}
			else break;
		}
		ret = max(ret, cnt);
	}
	cout << ret;
}