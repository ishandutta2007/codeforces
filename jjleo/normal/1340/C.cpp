#include <bits/stdc++.h>
#define maxn 10086

using namespace std;

int n, m;
int d[maxn];
int g, r;

deque<pair<int, int> > q;
int f[maxn][1005];
int ans = 1e9;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++) scanf("%d", &d[i]);
	sort(d + 1, d + 1 + m);
	scanf("%d%d", &g, &r);
	memset(f, -1, sizeof(f));
	f[1][0] = 0, q.push_front({1, 0});
	while(!q.empty()){
		pair<int, int> p = q.front();q.pop_front();
		//printf("%d %d--\n", p.first, p.second);
		if(p.second == g){
			q.push_back({p.first, 0});
			f[p.first][0] = f[p.first][p.second] + g + r;
			continue;
		}
		if(!p.second && n - d[p.first] <= g){
			ans = min(ans, f[p.first][p.second] + n - d[p.first]);
			continue;
		}
		//printf("%d %d %d--\n", p.first - 1, p.second + d[p.first] - d[p.first - 1], f[id(p.first - 1, (p.second + d[p.first] - d[p.first - 1]) % g)]);
		if(p.first > 1 && p.second + d[p.first] - d[p.first - 1] <= g && f[p.first - 1][p.second + d[p.first] - d[p.first - 1]] == -1){
			q.push_front({p.first - 1, p.second + d[p.first] - d[p.first - 1]});
			f[p.first - 1][p.second + d[p.first] - d[p.first - 1]] = f[p.first][p.second];
		}
		if(p.first < m && p.second + d[p.first + 1] - d[p.first] <= g && f[p.first + 1][p.second + d[p.first + 1] - d[p.first]] == -1){
			q.push_front({p.first + 1, p.second + d[p.first + 1] - d[p.first]});
			f[p.first + 1][p.second + d[p.first + 1] - d[p.first]] = f[p.first][p.second];
		}
	}
	printf("%d", ans == 1e9 ? -1 : ans);
	 
}