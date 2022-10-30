#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, q;
char s[maxn];
int l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &q, s + 1);
		while(q--){
			scanf("%d%d", &l, &r);
			bool tag = false;
			for(int i = 1;i < l && !tag;i++) if(s[i] == s[l]) tag = true;
			for(int i = r + 1;i <= n && !tag;i++) if(s[i] == s[r]) tag = true;
			puts(tag ? "YES" : "NO");
		}
	}
	
}