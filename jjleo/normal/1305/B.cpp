#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
char s[maxn];
bool vis[maxn];
int ans;

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int i = 1, j = n;
	while(i < j){
		while(s[i] != '(' && i <= n) ++i;
		while(s[j] != ')' && j) --j;
		if(i >= j) break;
		ans += 2;
		vis[i] = vis[j] = true;
		i++, j--;
		
	}
	if(!ans) return printf("0"), 0;
	printf("1\n%d\n", ans);
	for(int i = 1;i <= n;i++) if(vis[i]) printf("%d ", i);
}