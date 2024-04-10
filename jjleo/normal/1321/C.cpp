#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
char s[maxn];
int ans;
int pre[maxn], nxt[maxn];

int main(){
	scanf("%d%s", &n, s + 1);
	for(int i = 0;i <= n + 1;i++) pre[i] = i - 1, nxt[i] = i + 1;
	for(int i = 25;i;i--){
		for(int j = nxt[0];j != n + 1;j = nxt[j]){
			if(s[j] == i + 'a' && (s[pre[j]] == i + 'a' - 1 || s[nxt[j]] == i + 'a' - 1)){
				ans++;
				nxt[pre[j]] = nxt[j], pre[nxt[j]] = pre[j];
			}
		}
		for(int j = pre[n + 1];j;j = pre[j]){
			if(s[j] == i + 'a' && (s[pre[j]] == i + 'a' - 1 || s[nxt[j]] == i + 'a' - 1)){
				ans++;
				nxt[pre[j]] = nxt[j], pre[nxt[j]] = pre[j];
			}
		}
	}
	printf("%d", ans);
}