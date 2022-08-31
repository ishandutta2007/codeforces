#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, q;
priority_queue<pi, vector<pi>, greater<pi> > pq;

int applast[300005];
int cnt[300005], fcnt;
int point[300005];

int main(){
	cin >> n >> q;
	int v = 0;
	for(int i=1; i<=q; i++){
		int type, val;
		scanf("%d %d",&type, &val);
		if(type == 1){
			pq.push(pi(i, val));
			point[++v] = i;
			fcnt++;
			cnt[val]++;
		}
		if(type == 2){
			applast[val] = i;
			fcnt -= cnt[val];
			cnt[val] = 0;
		}
		if(type == 3){
			while(!pq.empty() && pq.top().first <= point[val]){
				if(applast[pq.top().second] < pq.top().first){
					cnt[pq.top().second]--;
					fcnt--;
				}
				pq.pop();
			}
		}
		printf("%d\n", fcnt);
	}
}