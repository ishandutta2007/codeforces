#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int t;
int n, m;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		int ans = 1;
		bool tag = false;
		while(n--){
			scanf("%s", s + 1);
			for(int i = 1;i <= m;i++){
				if(s[i] == '#') ans = (ans + ans) % p;
				else tag = true;
			}
		}
		if(!tag) ans = (ans + p - 1) % p;
		printf("%d\n", ans);
	}
}