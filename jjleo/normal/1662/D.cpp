#include <bits/stdc++.h>
#define maxn 100086

typedef long long ll;

using namespace std;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}
int n, m;

char s[maxn], t[maxn], S[maxn];

int solve(char *s, int n){
	int app[4] = {0, 0, 0};
	for(int i = 1; i <= n; i++){
		app[s[i] - 'A'] ++;
	}
	int nn = 0;
	if(app[1] & 1) S[++nn] = 'B';
	for(int i = 1; i <= n; i++){
		if(s[i] == 'B') continue;
		if(s[i] != S[nn]) S[++nn] = s[i];
		else nn--;
	}
	for(int i = 1; i <= nn; i++) s[i] = S[i];
	return nn;
}

int main(){
	int T = read();
	while(T--){
		scanf("%s", s + 1), scanf("%s", t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		n = solve(s, n);
		m = solve(t, m);
		if(n != m) puts("NO");
		else {
			bool f = 0;
			for(int i = 1; i <= m; i++) if(s[i] != t[i]) f = 1;
			puts(f ? "NO" : "YES");
		}
	}
}