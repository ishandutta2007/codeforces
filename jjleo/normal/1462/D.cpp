#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
		for(int i = n;i;i--){
			if(sum % i) continue;
			int x = sum / i;
			int val = 0, cnt = 0;
			bool tag = false;
			for(int j = 1;j <= n && !tag;j++){
				val += a[j];
				if(val == x) val = 0, cnt++;
				else if(val > x) tag = true;
			}
			if(!tag){
				printf("%d\n", n - i);
				break;
			}
		}
	}
}