#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];
int fa[maxn];
bool tag[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n * 2;i++) tag[i] = false;
		int ans = 0;
		int cnt = 1, now = cnt;
		for(int i = 1;i <= n * 2;i++){
			if(s[i] == '('){
				int x = ++cnt;
				fa[x] = now;
				if(!tag[now]) tag[now] = true, ans++;
				now = x;
			}else{
				now = fa[now];
			}
		}
		printf("%d\n", ans);
	}
}