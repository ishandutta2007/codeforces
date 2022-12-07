#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];
int a[maxn], mn;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 0;i < 26;i++) a[i] = 0;
		mn = 26;
		for(int i = 1;i <= n;i++) a[s[i] - 'a']++, mn = min(mn, s[i] - 'a');
		if(a[mn] == n){
			printf("%s\n", s + 1);
			continue;
		}
		bool tag = false;
		for(int i = 0;i < 26;i++){
			if(a[i] == 1){
				printf("%c", i + 'a'), a[i] = 0;
				for(int j = 0;j < 26;j++) for(int k = 1;k <= a[j];k++) printf("%c", j + 'a');
				puts(""); 
				tag = true;
				break;
			}
		}
		if(tag) continue;
		if(a[mn] - 2 > n - a[mn]){
			int x;
			for(int i = mn + 1;;i++){
				if(a[i]){
					x = i;
					break;
				}
			}
			if(a[mn] + a[x] == n){
				printf("%c", mn + 'a'); 
				for(int i = 1;i <= a[x];i++) printf("%c", x + 'a');
				for(int i = 1;i < a[mn];i++) printf("%c", mn + 'a');
				puts("");
				continue;
			}
			printf("%c", mn + 'a'), a[mn]--;
			printf("%c", x + 'a'), a[x]--;
			while(a[mn]--) printf("%c", mn + 'a');
			for(int i = x + 1;;i++){
				if(a[i]){
					printf("%c", i + 'a'), a[i]--;
					break;
				}
			}
			for(int j = mn + 1;j < 26;j++) for(int k = 1;k <= a[j];k++) printf("%c", j + 'a');
			puts("");
			continue;
		}
		printf("%c", mn + 'a'), a[mn]--;
		printf("%c", mn + 'a'), a[mn]--;
		int x = mn + 1;
		while(1){
			while(!a[x] && x < 26) x++;
			if(x == 26) break;
			printf("%c", x + 'a'), a[x]--;
			if(a[mn]) printf("%c", mn + 'a'), a[mn]--;
		}
		puts("");
	}
}