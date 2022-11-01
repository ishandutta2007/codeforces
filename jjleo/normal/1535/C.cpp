#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
char s[maxn];
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int last, st, tmp = 0;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			bool tag = false;
			if(i == 1) tag = true;
			else{
				if(st == -1) st = s[i] == '?' ? -1 : s[i] - '0';
				else if(s[i] != '?' && s[i] - '0' == st) tag = true;
				else st ^= 1; 
			}
			if(tag){
				last = tmp + 1;
				st = s[i] == '?' ? -1 : s[i] - '0';
			}
			if(s[i] != '?') tmp = i;
			ans += i - last + 1; 
		}
		printf("%lld\n", ans);
	}
}