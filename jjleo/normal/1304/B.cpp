#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n, m;
char s[maxn][maxn];
vector<int> v;
bool vis[maxn];
int mid;

inline bool f(int x, int y){
	for(int i = 1;i <= m;i++) if(s[x][i] != s[y][m + 1 - i]) return false;
	return true;
} 

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		for(int j = i + 1;j <= n;j++){
			if(!vis[j] && f(i, j)){
				vis[i] = vis[j] = true;
				v.push_back(i);
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i] && f(i, i)){
			mid = i;
			break;
		}
	}
	printf("%d\n", v.size() * 2 * m + (mid != 0) * m);
	for(int i = 0;i < v.size();i++) printf("%s", s[v[i]] + 1);
	if(mid) printf("%s", s[mid] + 1);
	for(int i = (int)v.size() - 1;i >= 0;i--) for(int j = m;j;j--) printf("%c", s[v[i]][j]);
}