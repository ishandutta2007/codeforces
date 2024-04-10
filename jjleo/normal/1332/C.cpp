#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
char s[maxn];
int num[26], now, sum, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		ans = 0;
		for(int i = 1;i <= k + 1 - i;i++){
			memset(num, 0, sizeof(num));
			now = sum = 0;
			for(int j = i;j <= n;j += k){
				num[s[j] - 'a']++, sum++;
				if(num[s[j] - 'a'] > num[now]) now = s[j] - 'a';
			} 
			
			if(i ^ (k + 1 - i)){
				for(int j = k + 1 - i;j <= n;j += k){
					num[s[j] - 'a']++, sum++;
					if(num[s[j] - 'a'] > num[now]) now = s[j] - 'a';
				} 
			}
			ans += sum - num[now];
		}
		printf("%d\n", ans);
	}
}