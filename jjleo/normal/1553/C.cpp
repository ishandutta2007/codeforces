#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n = 10;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		int ans = 10, cnt1 = 0, cnt2 = 0;
		for(int i = 1;i <= n;i++){
			if(i & 1){
				if(s[i] != '0') cnt1++;
				if(cnt1 - cnt2 > (n - i + 1) / 2){
					ans = min(ans, i);
					break;
				}
			}else{
				if(s[i] == '1') cnt2++;
				if(cnt1 - cnt2 > (n - i) / 2){
					ans = min(ans, i);
					break;
				}
			}
		}
		cnt1 = cnt2 = 0;
		for(int i = 1;i <= n;i++){
			if(!(i & 1)){
				if(s[i] != '0') cnt1++;
				if(cnt1 - cnt2 > (n - i) / 2){
					ans = min(ans, i);
					break;
				}
			}else{
				if(s[i] == '1') cnt2++;
				if(cnt1 - cnt2 > (n - i) / 2){
					ans = min(ans, i);
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}