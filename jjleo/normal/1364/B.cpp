#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
bool tag[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) tag[i] = false;
		int cnt = n;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(i > 2 && 1ll * (a[i] - a[i - 1]) * (a[i - 1] - a[i - 2]) > 0) tag[i - 1] = true, cnt--;
		}
		printf("%d\n", cnt);
		for(int i = 1;i <= n;i++) if(!tag[i]) printf("%d ", a[i]);
		puts("");
	}
}