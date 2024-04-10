#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
char s[maxn];
int n;
int a[26];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) a[s[i] - 'A']++;
		if(a['S' - 'A'] >= a['R' - 'A'] && a['S' - 'A'] >= a['P' - 'A']){
			for(int i = 1;i <= n;i++) printf("R");
			puts("");
		}else if(a['R' - 'A'] >= a['S' - 'A'] && a['R' - 'A'] >= a['P' - 'A']){
			for(int i = 1;i <= n;i++) printf("P");
			puts("");
		}else{
			for(int i = 1;i <= n;i++) printf("S");
			puts("");
		}
	}
}