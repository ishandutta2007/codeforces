#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int T, n, m;
char s[maxn], t[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1);
		int x = 0;
		for(int i = 1;i <= n && x < m;i++){
			if((n & 1) != ((i + m - x) & 1) && s[i] == t[x + 1]) x++;
		}
		puts(x == m ? "YES" : "NO");
	}
}