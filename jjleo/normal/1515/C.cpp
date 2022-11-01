#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, x;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

int id[maxn], cnt;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &x);
		while(!q.empty()) q.pop();
		for(int i = 1;i <= m;i++) q.push({0, i}); 
		puts("YES"); 
		while(n--){
			int xx;
			scanf("%d", &xx);
			int x = q.top().first, y = q.top().second;q.pop();
			printf("%d ", y);
			q.push({x + xx, y});
		}
		puts("");
	}
}