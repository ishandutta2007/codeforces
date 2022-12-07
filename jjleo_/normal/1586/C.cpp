#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, m, q;
string s[maxn];
char S[maxn];
int a[maxn];
int l, r;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) scanf("%s", S), s[i] = S;
	for(int i = 1;i < n;i++) for(int j = 0;j + 1 < m;j++) if(s[i][j] == 'X' && s[i - 1][j + 1] == 'X') a[j] = 1;
	for(int i = 1;i + 1 < m;i++) a[i] += a[i - 1];
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &l, &r);
		l--, r--;
		puts((r == 0 ? 0 : a[r - 1]) - (l == 0 ? 0 : a[l - 1]) ? "NO" : "YES");
	}
}