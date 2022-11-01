#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n, k;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		bool tag = false;
		for(int i = 1;i + k <= n;i++){
			if(s[i] == '?' && s[i + k] == '?') continue;
			if(s[i] == '?') s[i] = s[i + k];
			else if(s[i + k] == '?') s[i + k] = s[i];
			else if(s[i] != s[i + k]){
				tag = true;
				break;
			}
		}
		for(int i = n;i - k > 0;i--){
			if(s[i] == '?' && s[i - k] == '?') continue;
			if(s[i] == '?') s[i] = s[i - k];
			else if(s[i - k] == '?') s[i - k] = s[i];
			else if(s[i] != s[i - k]){
				tag = true;
				break;
			}
		}
		if(tag){
			puts("NO");
			continue;
		}
		int x = 0, y = 0;
		for(int i = 1;i <= k;i++){
			if(s[i] == '0') x--;
			else if(s[i] == '1') x++;
			else y++;
		}
		if(abs(x) <= y) puts("YES");
		else puts("NO");
	}
}