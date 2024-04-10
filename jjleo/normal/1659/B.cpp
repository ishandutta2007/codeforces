#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, k;
char s[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		for(int i = 1;i <= n;i++) f[i] = 0;
		int K = k;
		for(int i = 1;i <= n;i++){
			if(K % 2 == 0){
				if(s[i] == '0' && k) s[i] = '1', k--, f[i]++;
			}else{
				if(s[i] == '1' && k) k--, f[i]++;
				else s[i] = (int)'1' + '0' - s[i];
			}
		}
		if(k & 1) s[n] = '0';
		f[n] += k;
		printf("%s\n", s + 1);
		for(int i = 1;i <= n;i++) printf("%d ", f[i]);puts("");
	}
}