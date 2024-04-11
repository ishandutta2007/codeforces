#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
//typedef pair<int, int> pi;
const int MAXN = 200005;

struct pi{
	int first, second, fuck;
	bool operator<(const pi &c)const{
		return make_pair(first, second) < make_pair(c.first, c.second);
	}
}a[MAXN];

priority_queue<pi> pq;
int sum, n, t;

int main(){
	cin >> n >> t;
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		a[i].fuck = i+1;
	}
	sort(a, a+n);
	reverse(a, a+n);
	int p = 0;
	int ans = 0, pos = 0;
	for(int i=n; i; i--){
		while(p < n && a[p].first >= i){
			pq.push({a[p].second, 0, a[p].fuck});
			sum += a[p].second;
			p++;
		}
		while(pq.size() > i){
			sum -= pq.top().first;
			pq.pop();
		}
		if(sum <= t){
			int cur = pq.size();
			if(cur > ans){
				ans = cur;
				pos = i;
			}
		}
	}
	if(ans == 0){
		cout << 0 << endl << 0 << endl << endl;
		return 0;
	}
	while(!pq.empty()) pq.pop();
	for(int i=0; i<n; i++){
		if(a[i].first >= ans){
			pq.push({a[i].second, 0, a[i].fuck});
		}
	}
	while(pq.size() > ans) pq.pop();
	printf("%d\n%d\n", ans, ans);
	while(!pq.empty()) printf("%d ", pq.top().fuck), pq.pop();
}