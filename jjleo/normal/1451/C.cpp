#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n, k;
char s[maxn];
int a[26];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) a[s[i] - 'a']++;
		scanf("%s", s + 1);
		for(int i = 1;i <= n;i++) a[s[i] - 'a']--;
		int x = 0;
		bool tag = true;
		for(int i = 0;i < 26;i++){
			x += a[i];
			if(x % k || x < 0){
				tag = false;
				break;
			}
		}
		puts(tag ? "Yes" : "No");
	}
}