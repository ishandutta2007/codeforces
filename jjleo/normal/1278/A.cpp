#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
char s[maxn], h[maxn];
int a[26], b[26];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s%s", s + 1, h + 1);
		n = strlen(s + 1), m = strlen(h + 1);
		bool tag = false;
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) a[s[i] - 'a']++;
		for(int i = 1;i + n - 1 <= m;i++){
			memset(b, 0, sizeof(b));
			for(int j = i;j <= i + n - 1;j++) b[h[j] - 'a']++;
			for(int j = 0;j < 26;j++){
				if(a[j] ^ b[j]) break;
				if(j == 25) tag = true;
			}
			if(tag) break;
		}
		puts(tag ? "YES" : "NO");
	}
}