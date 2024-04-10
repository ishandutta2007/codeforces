#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t;
int n;
int a[maxn];
int ans[maxn * maxn], cnt;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), cnt = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i < n - 1;i++){
			int id = i;
			for(int j = i;j <= n;j++) if(a[j] < a[id]) id = j;
			while(id > i){
				if(id - i == 1){
					swap(a[id + 1], a[id]), swap(a[id], a[id - 1]);
					ans[++cnt] = id - 1, id++;
				}else{
					swap(a[id], a[id - 1]), swap(a[id - 1], a[id - 2]);
					ans[++cnt] = id - 2, id -= 2;
				}
			}
		}
		 
		
		if(a[n - 1] > a[n]){
			bool tag = false;
			if(a[n] == a[n - 2]) ans[++cnt] = n - 2;
			else{
				for(int i = n - 3;i;i--){
					if(a[i] == a[i + 1]){
						for(int j = i;j <= n - 2;j ++){
							ans[++cnt] = j, ans[++cnt] = j;
							//swap(a[j + 2], a[j + 1]), swap(a[j + 1], a[j]);
							//swap(a[j + 2], a[j + 1]), swap(a[j + 1], a[j]);
						}
						tag = true;
						break;
					}
				}
				if(!tag){
					puts("-1");
					continue;
				}
			}
		}
		//for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		//puts("---");
		printf("%d\n", cnt);
		for(int i = 1;i <= cnt;i++) printf("%d ", ans[i]);
		puts("");
	} 
}