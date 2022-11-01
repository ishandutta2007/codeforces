#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 1e9 + 7;

int n;
char s[maxn];
int pre[maxn], pos[maxn], to[maxn][2];
int f[maxn];

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int I = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '1'){
			I = i;
			break;
		}
	}
	if(!I) return printf("%d", n) , 0;
	for(int i = I;i <= n;i++){
		if(s[i] == '1') pre[i] = 0;
		else pre[i] = pre[i - 1] + 1;
	}
	for(int i = 0;i <= n;i++) pos[i] = n + 1;
	for(int i = n;i >= I;i--){ 
		to[i][1] = pos[0];
		to[i][0] = pos[pre[i] + 1];
		pos[pre[i]] = i;
	}
	f[I] = I;
	for(int i = I;i < n;i++){
		if(to[i][0] <= n) f[to[i][0]] = (f[to[i][0]] + f[i]) % p;
		if(to[i][1] <= n) f[to[i][1]] = (f[to[i][1]] + f[i]) % p;
	}
	int ans = 0;
	for(int i = I;i <= n;i++) if(pre[i] <= pre[n]) ans = (ans + f[i]) % p;
	printf("%d", ans);
};