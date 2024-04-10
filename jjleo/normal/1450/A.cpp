#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		sort(s + 1, s + 1 + n);
		printf("%s\n", s + 1);
	}
}