#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int num = 0, ans = 0;
		for(int i = 1;i <= n;i++){
			++num;
			if(num == a[i]) num = 0, ans++;
		}
		printf("%d\n", ans);
	}
}