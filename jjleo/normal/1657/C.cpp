#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int ans = 0, last = 1;
		while(last < n){
			if(s[last] == s[last + 1] || s[last] == '(' && s[last + 1] == ')'){
				last += 2;
				ans++;
				continue;
			} 
			bool tag = false;
			for(int j = last + 2;j <= n;j++){
				if(s[j] == ')'){
					tag = true;
					ans++;
					last = j + 1;
					break;
				}
			}
			if(!tag) break;
		}
		printf("%d %d\n", ans, n - last + 1);
	}
}