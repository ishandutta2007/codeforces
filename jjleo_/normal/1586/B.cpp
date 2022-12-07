#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
bool tag[maxn];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) tag[i] = false;
		while(m--) scanf("%d", &x), scanf("%d", &x), tag[x] = true, scanf("%d", &x);
		for(int i = 1;i <= n;i++) if(!tag[i]) x = i;
		for(int i = 1;i <= n;i++) if(x ^ i) printf("%d %d\n", i, x);
	}
}