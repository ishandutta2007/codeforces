#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x;
int num[2];
bool a[200];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(num, 0, sizeof(num)), memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			num[x & 1]++;
			a[x] = true;
		}
		if(num[0] & 1){
			bool suc = false;
			for(int i = 2;i <= 100;i++){
				if(a[i] && a[i - 1]){
					puts("YES"), suc = true;
					break;
				}
			}
			if(!suc) puts("NO");
		}else{
			puts("YES");
		}
	}
}