#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
char s[maxn];
int cnt[26];

void solve(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 0;i < 26;i++) cnt[i] = 0;
	for(int i = 1;i <= n;i++) cnt[s[i] - 'a']++;
	int tot = 0;
	for(int i = 0;i < 26;i++) tot += cnt[i] != 0;
	if(tot == 1){
		puts("YES");
		return;
	}
	if(tot == 2){
		bool tag = false;
		for(int i = 2;i <= n;i++) if(s[i] == s[i - 1]) tag = true;
		puts(tag ? "NO" : "YES");
		return;
	}
	for(int i = 0;i < 26;i++) for(int j = 0;j < 26;j++) if(i != j && cnt[i] && cnt[j]){
		int sum = 0;
		int mn = 0;
		for(int k = 1;k <= n;k++){
			if(s[k] == i + 'a') sum++;
			else if(s[k] == j + 'a') sum--;
			if(sum - mn > 1){
				puts("NO");
				return;
			}
			mn = min(mn, sum);
		}
	} 
	puts("YES");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
	
}