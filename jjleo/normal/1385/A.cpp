#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a[4];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1;i <= 3;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 4);
		if(a[2] ^ a[3]){
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d %d %d\n", a[1], a[1], a[2]);
		
	}
}