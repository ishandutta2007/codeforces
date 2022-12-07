#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], l[maxn], r[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) l[i] = i > 1 && a[i] > a[i - 1] ? l[i - 1] + 1 : 0;
	for(int i = n;i;i--) r[i] = i < n && a[i] > a[i + 1] ? r[i + 1] + 1 : 0;
	int len = 0;
	for(int i = 1;i <= n;i++) len = max(len, max(l[i], r[i]));
	if(len & 1) return printf("0"), 0;
	int ans = 0, cnt = 0;
	for(int i = 1;i <= n;i++){
		ans += l[i] == r[i] && l[i] == len;
		cnt += max(l[i], r[i]) == len;
	}
	printf("%d", cnt > 1 ? 0 : ans);
}