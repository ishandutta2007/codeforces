#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi> limit;
int n,m;
const int N = 2010;
int x1[N], y1[N], x2[N], y2[N];
vector<pi> mx;

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> x1[i] >> y1[i];
	for(int i=1;i<=m;i++)cin >> x2[i] >> y2[i];
	limit.push_back(pi(0,0x3f3f3f3f));
	limit.push_back(pi(0x3f3f3f3f,0));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		pi l(0,0);
		l.second = max(l.second, x2[j] - x1[i] + 1);
		l.first = max(l.first, y2[j] - y1[i] + 1);
		limit.push_back(l);
		// cout << l.first << ":" << l.second << endl;
	}
	sort(limit.begin(), limit.end());
	mx = limit;
	int sz = limit.size();
	int ans = 0x3f3f3f3f;
	for(int i=sz-2;~i;i--){
		limit[i].second = max(limit[i].second, limit[i+1].second);
		ans = min(ans, limit[i+1].second+ limit[i].first);
	}
	cout << ans << endl;
}