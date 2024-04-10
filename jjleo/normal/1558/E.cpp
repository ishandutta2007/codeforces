#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

typedef long long ll;

int t, n, m;
vector<int> v[maxn];
int x, y;
int a[maxn], b[maxn];
bool tag[maxn];
queue<pair<int, ll> > q;
int from[maxn];

bool check(ll val){
	for(int i = 1;i <= n;i++) tag[i] = i == 1;
	while(1){
		while(!q.empty()) q.pop();
		bool ok = false;
		for(int i = 1;i <= n;i++){
			if(tag[i]) q.push({i, val});
			from[i] = 0;
		}
		while(!q.empty()){
			int x = q.front().first;
			ll y = q.front().second;q.pop();
			//printf("%lld %d %d %d--\n", val, x, from[x], y);
			for(int i = 0;i < v[x].size();i++){
				int to = v[x][i];
				if(to == from[x] || tag[x] && tag[to] || y <= a[to]) continue;
				if(from[to] || tag[to]){
					//printf("%d %d %d--\n", x, to, from[to]);
					while(!tag[x]) tag[x] = true, val += b[x], x = from[x];
					x = to;
					while(!tag[x]) tag[x] = true, val += b[x], x = from[x];
					ok = true;
					break;
				}
				from[to] = x;
				q.push({to, y + b[to]});
				//printf("%d %d--\n", x, to);
			}
			if(ok) break;
		}
		if(!ok) return false;
		int cnt = 0;
		for(int i = 1;i <= n;i++) cnt += tag[i];
		if(cnt == n) return true;
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 2;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 2;i <= n;i++) scanf("%d", &b[i]);
		for(int i = 1;i <= n;i++) v[i].clear();
		while(m--){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		//check(526745372);
		int l = 1, r = 1e9 + 1, mid;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}
/*
1
27 54
730807132 835673719 375786934 492063549 695722542 915286349 450714392 724015142 401896916 958210700 977791519 461224456 14185637 964013971 713133785 693496717 363727369 942697204 202135468 318095825 742222590 210859765 185582542 560422629 14728342 504363026
1230516 34285479 35948074 9184300 1040276 32451983 24338394 20809969 1562890 25450696 23794486 36400390 36549128 35825024 18176205 25324560 19776922 19886981 2487851 9003879 29554143 31429846 23377746 30588854 23983288 14075159
24 15
5 24
14 27
2 10
7 21
8 19
6 23
2 8
5 14
25 10
16 5
26 4
14 6
8 11
14 2
6 10
12 6
15 9
24 20
19 3
1 16
1 17
5 1
26 5
3 13
18 9
26 6
1 7
24 27
27 7
22 8
7 12
14 10
27 12
21 17
17 3
26 17
20 12
12 18
11 15
19 25
20 4
5 15
13 26
15 25
2 27
26 12
22 18
5 4
11 1
3 4
22 12
27 5
10 23
*/