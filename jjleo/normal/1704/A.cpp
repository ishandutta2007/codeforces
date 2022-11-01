#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
char a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
		bool tag = false;
		for(int i = 0;i < m - 1;i++){
			if(a[n - i] != b[m - i]){
				tag = true;
				break;
			}
		}
		if(tag){
			puts("NO");
			continue;
		}
		for(int i = 1;i <= n - m + 1;i++){
			if(a[i] == b[1]){
				tag = true;
				break;
			}
		}
		puts(tag ? "YES" : "NO");
	}
}