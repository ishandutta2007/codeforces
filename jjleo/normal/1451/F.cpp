#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int t;
int n, m;
int x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &x), a[i + j] ^= x;
		bool tag = false;
		for(int i = 2;i <= n + m && !tag;i++) tag |= a[i];
		puts(tag ? "Ashish" : "Jeel");
	}
}//