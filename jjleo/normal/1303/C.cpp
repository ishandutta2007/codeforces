#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];
int len;
int l[300], r[300];
bool vis[300];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1), len = strlen(s + 1);
		bool suc = true;
		memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r)), memset(vis, 0, sizeof(vis));
		vis[s[1]] = true;
		for(int i = 2;i <= len;i++){
			if(l[s[i - 1]] == s[i] || r[s[i - 1]] == s[i]) continue;
			if(l[s[i - 1]] && r[s[i - 1]]){
				suc = false;
				puts("NO");
				break;
			}
			if(vis[s[i]]){
				suc = false;
				puts("NO");
				break;
			}
			vis[s[i]] = true;
			if(!l[s[i - 1]]) l[s[i - 1]] = s[i], r[s[i]] = s[i - 1];
			else r[s[i - 1]] = s[i], l[s[i]] = s[i - 1];
		}
		if(!suc) continue;
		puts("YES");
		memset(vis, 0, sizeof(vis));
		int x = s[1];
		while(l[x]) x = l[x];
		while(x) printf("%c", x), vis[x] = true, x = r[x];
		for(int i = 'a';i <= 'z';i++) if(!vis[i]) printf("%c", i);puts("");
	}
}