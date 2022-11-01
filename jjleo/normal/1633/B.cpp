#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int cnt = 0;
		for(int i = 1;i <= n;i++) cnt += s[i] == '0';
		if(cnt == n - cnt) printf("%d\n", cnt - 1);
		else printf("%d\n", min(cnt, n - cnt));
	}
}