#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn], c[maxn];

bool solve(){
	scanf("%s%s", s + 1, c + 1);
	int n = strlen(s + 1);
	for(int i = 1;i <= n;i += 2) if(s[i] == c[1]) return true;
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO"); 
}