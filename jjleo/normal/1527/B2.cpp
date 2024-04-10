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
		int sum = 0, cnt = 0, tot = 0;
		for(int i = 1;i <= n;i++){
			sum += s[i] == '0';
			cnt += (i < n - i + 1) && s[i] != s[n - i + 1];
			tot += (i < n - i + 1) && s[i] == s[n - i + 1] && s[i] == '0';
		}
		if(cnt){
			if(tot == 0 && cnt == 1 && (n & 1) && s[n / 2 + 1] == '0') puts("DRAW");
			else puts("ALICE");
			continue; 
		}
		if(sum == 0) puts("DRAW");
		else puts((sum & 1) && sum > 1 ? "ALICE" : "BOB");
	}
}