#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
char l[maxn], r[maxn];

int main(){
	scanf("%d%s%s", &n, l + 1, r + 1);
	if(l[1] ^ r[1]){
		for(int i = 1;i <= n;i++) printf("1");
		return 0;
	}
	if(r[n] == '1') return printf("%s", r + 1), 0;
	l[n] += 2;
	for(int i = n;i;i--) if(l[i] > '1') l[i] -= 2, l[i - 1]++;
	if(!l[0] && strcmp(l + 1, r + 1) <= 0) r[n]++;
	printf("%s", r + 1);
}