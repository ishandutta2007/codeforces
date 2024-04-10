#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Node{
	int edge[26], len, link;
}t[maxn];

int cnt, last;
char s[maxn];


void init(){
	for(int i = 0;i <= cnt;i++) memset(t[i].edge, 0, sizeof(t[i].edge)), t[i].len = t[i].link = 0;
	cnt = 1;
	t[0].len = 0;
	t[0].link = 1;
	t[1].len = -1;//debug 0 
	last = 0;
}

int getfail(int x, int y){
	while(s[y - t[x].len - 1] != s[y]) x = t[x].link;//debug:-1 yx -len-1 
	return x;
} 


void insert(char c, int y){
	int x = c - 'a';
	int z = getfail(last, y);
	if(!t[z].edge[x]){
		int cur = ++cnt;
		t[cur].len = t[z].len + 2;
		t[cur].link = t[getfail(t[z].link, y)].edge[x];// 
		t[z].edge[x] = cur;
	}
	last = t[z].edge[x];
}

char b[maxn];
int T;
int ans;
int n;

int main(){
	scanf("%d", &T);
	while(T--){
		ans = 0;
		scanf("%s", b + 1);
		n = strlen(b + 1);
		int a = 1;
		for(;a <= n && b[a] == b[n + 1 - a];a++);a--;
		if(a == n){
			printf("%s\n", b + 1);
			continue;
		}
		for(int i = 1;i <= n - 2 * a;i++) s[i] = b[i + a];
		init();
		for(int i = 1;i <= n - 2 * a;i++){
			insert(s[i], i);
			if(t[last].len == i) ans = t[last].len;
		}
		if(t[last].len > ans) ans = -t[last].len;
		for(int i = 1;i <= a;i++) printf("%c", b[i]);
		if(ans > 0) for(int i = 1;i <= ans;i++) printf("%c", s[i]);
		else for(int i = n - 2 * a + 1 + ans;i <= n - 2 * a;i++) printf("%c", s[i]);
		for(int i = n + 1 - a;i <= n;i++) printf("%c", b[i]);
		puts("");
	}
}