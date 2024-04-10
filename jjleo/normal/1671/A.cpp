#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(s[i] != s[i - 1] && s[i] != s[i + 1]){
				tag = true;
				break;
			}
		}
		puts(tag ? "NO" : "YES");
	}
}