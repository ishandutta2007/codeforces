#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		bool tag = false;
		int ans = 0;
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(!tag && s[i] == 'P') continue;
			tag = true;
			if(s[i] == 'A') ans = max(ans, sum), sum = 0;
			else ++sum;
		}
		ans = max(ans, sum);
		printf("%d\n", ans);
	}
}