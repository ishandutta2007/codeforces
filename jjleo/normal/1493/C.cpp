#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
char s[maxn];
int a[maxn];
int cnt[26];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &m, s + 1);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1;i <= n;i++) a[i] = s[i] - 'a', cnt[a[i]]++;
		bool tag = false;
		long long sum = 0;
		for(int k = 0;k < 26;k++) sum += cnt[k] % m ? m - cnt[k] % m : 0;
		if(sum == 0){
			tag = true;
			printf("%s\n", s + 1);
		}
		for(int i = n;i && !tag;i--){
			cnt[a[i]]--;
			for(int j = a[i] + 1;j < 26 && !tag;j++){
				cnt[j]++;
				long long sum = 0;
				for(int k = 0;k < 26;k++) sum += cnt[k] % m ? m - cnt[k] % m : 0;
				if(sum <= n - i && (n - i - sum) % m == 0){
					tag = true;
					for(int k = 1;k < i;k++) printf("%c", s[k]);
					printf("%c", j + 'a');
					for(int k = n - i - sum;k;k--) printf("a");
					for(int k = 0;k < 26;k++) for(int l = cnt[k] % m ? m - cnt[k] % m : 0;l;l--) printf("%c", k + 'a');
					puts("");
				}
				cnt[j]--;
			}
			
		}
		if(!tag) puts("-1");
	}
}