#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];
int n;
int a[2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		a[0] = a[1] = 0;
		for(int i = 1;i <= n;i++){
			a[s[i] - '0']++;
		}
		puts((min(a[0], a[1]) & 1) ? "DA" : "NET");
	}
}