#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn], b[maxn];
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		int pos = n + 1;
		for(int i = n;i;i--){
			while(pos > 1 && b[pos - 1] >= a[i]) pos--;
			ans[i] = b[pos] - a[i];
		} 
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);puts("");
		pos = n + 1;
		int cnt = 0, mx = b[n];
		for(int i = n;i;i--){
			while(pos > 1 && b[pos - 1] >= a[i]) pos--, cnt++;
			cnt--;
			ans[i] = mx - a[i];
			if(cnt == 0) mx = b[pos - 1];
		}
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);puts("");
	}
}