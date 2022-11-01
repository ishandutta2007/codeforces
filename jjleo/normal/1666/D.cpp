#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int T;
char s[maxn], t[maxn];

bool solve(){
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	int a[26] = {0}, b[26] = {0};
	for(int i = 1;i <= m;i++) a[t[i] - 'A']++;
	for(int i = 1;i <= n;i++) b[s[i] - 'A']++;
	for(int i = 0;i < 26;i++) if(a[i] > b[i]) return false;
	int now = 0;
	for(int i = 1;i <= n;i++){
		if(b[s[i] - 'A'] > a[s[i] - 'A']) b[s[i] - 'A']--;
		else{
			now++;
			if(t[now] != s[i]) return false;
		}
	}
	return true;
}

int main(){
	scanf("%d", &T);
	while(T--) puts(solve() ? "YES" : "NO");
}