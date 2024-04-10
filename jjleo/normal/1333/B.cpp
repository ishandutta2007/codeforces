#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn], cnt[3];
bool suc;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		suc = true;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		for(int i = 1;i <= n;i++){
			if(a[i] != b[i]){
				if((b[i] - a[i] > 0 && !cnt[2]) || (b[i] - a[i] < 0 && !cnt[0])){
					puts("NO");
					suc = false;
					break;
				}
			}
			cnt[a[i] + 1]++;
		}
		if(suc) puts("YES");
	}
}