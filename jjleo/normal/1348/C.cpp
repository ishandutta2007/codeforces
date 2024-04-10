#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
char s[maxn];
int a[26];
char b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) a[s[i] - 'a']++;
		int x = 0;
		for(int i = 0;i < 26;i++){
			if(!a[i]) continue;
			if(x == 0 && a[i] >= k){
				a[i] -= k;
				printf("%c", i + 'a');
				bool tag = false;
				for(int j = i;j < 26;j++){
					if(a[j]){
						for(int l = j + 1;l < 26;l++) if(a[l]) tag = true;
						break;
					}
				}
				if(tag){
					for(int j = i;j < 26;j++){
						for(int l = 1;l <= a[j];l++) printf("%c", j + 'a');
					}
				}else{
					for(int j = i;j < 26;j++){
						if(a[j]){
							int y = a[j] / k + (a[j] % k != 0);
							for(int l = 1;l <= y;l++) printf("%c", j + 'a');
							break;
						}
					}
				}
				break;
			}
			x += a[i];
			if(x >= k){
				printf("%c", i + 'a');
				break;
			}
		}
		puts("");
		//if(tag) continue;
	}
}