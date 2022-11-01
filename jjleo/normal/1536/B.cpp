#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];
bool tag;
char a[maxn];
int len;

void dfs(int i){
	if(tag) return;
	if(i > len){
		tag = true;
		for(int j = 1;j + len - 1 <= n;j++){
			bool flag = false;
			for(int k = 1;k <= len;k++){
				if(a[k] != s[j + k - 1]){
					flag = true;
					break;
				}
			}
			if(!flag){
				tag = false;
				break;
			}
		}
		if(tag){
			for(int j = 1;j <= len;j++) printf("%c", a[j]);
			puts("");
		}
		return;
	}
	for(int j = 0;j < 26;j++){
		a[i] = j + 'a';
		dfs(i + 1);
		if(tag) return;
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		tag = false;
		for(int i = 1;!tag;i++){
			len = i, dfs(1);
		}
	}
}