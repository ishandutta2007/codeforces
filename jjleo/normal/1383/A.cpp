#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char a[maxn], b[maxn];
bool f[20][20];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s%s", &n, a + 1, b + 1);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(a[i] > b[i]){
				tag = true;
				break;	
			}
		}
		if(tag){
			puts("-1");
			continue;
		}
		memset(f, 0, sizeof(f));
		for(int i = 1;i <= n;i++){
			if(a[i] < b[i]) f[a[i] - 'a'][b[i] - 'a'] = true;
		} 
		int ans = 0;
		for(int i = 0;i < 20;i++){
			for(int j = 0;j < 20;j++){
				if(f[i][j]){
					f[i][j] = false;
					ans++;
					for(int k = 0;k < 20;k++){
						f[j][k] |= f[i][k];
					}
					break;
				}
			}	
		}
		printf("%d\n", ans);
	}
}