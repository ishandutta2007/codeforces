#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int n;
pair<int, int> a[maxn];
int pos[maxn * 25];
vector<pair<int, int> > v[maxn * 25];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), a[i].second = i;
	sort(a + 1, a + 1 + n);
	for(int i = 2;i <= n;i++){
		int x = a[i].first - a[i - 1].first;
		if(!pos[x]) pos[x] = i;
		else if(pos[x] != i - 1){
			return printf("YES\n%d %d %d %d", a[pos[x] - 1].second, a[i].second, a[pos[x]].second, a[i - 1].second), 0;
		}
	} 
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			int x = a[i].first + a[j].first;
			for(int k = 0;k < v[x].size();k++){
				if(v[x][k].first != i && v[x][k].second != i && v[x][k].first != j && v[x][k].second != j){
					return printf("YES\n%d %d %d %d", a[i].second, a[j].second, a[v[x][k].first].second, a[v[x][k].second].second), 0;
				}
			}
			v[x].push_back({i, j});
		}
	}
	printf("NO");
}