#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 3005;

int n, m;
vector<int> v[MAXN];

lint solve(int c){
	int needy = c - v[1].size();
	priority_queue<int> pq;
	lint tot = 0;
	for(int i=2; i<=m; i++){
		for(int j=c-1; j<v[i].size(); j++){
			tot += v[i][j];
			needy--;
		}
		for(int j=0; j<c-1 && j<v[i].size(); j++) pq.push(-v[i][j]);
	}
	if(needy < 0) return 1e18;
	while(needy && !pq.empty()){
		tot -= pq.top();
		pq.pop();
		needy--;
	}
	if(needy) return 1e18;
	return tot;
}

int main(){
	cin >> n >> m;
	if(m == 1){
		puts("0");
		return 0;
	}
	for(int i=0; i<n; i++){
		int p, c;
		cin >> p >> c;
		v[p].push_back(c);
	}
	for(int i=1; i<=m; i++) sort(v[i].rbegin(), v[i].rend());
	lint ans = 1e18;
	for(int i=v[1].size(); i<=n; i++){
		if(i) ans = min(ans, solve(i));
	}
	cout << ans << endl;
}