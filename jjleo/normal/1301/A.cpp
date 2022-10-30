#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char a[maxn], b[maxn], c[maxn];

int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s%s%s", a + 1, b + 1, c + 1); 
		n = strlen(a + 1);
		for(int i = 1;i <= n;i++){
			if(!(a[i] == c[i] || b[i] == c[i])){
				puts("NO");
				break;
			}
			if(i == n) puts("YES");
		}
	}
}