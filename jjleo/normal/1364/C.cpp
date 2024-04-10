#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], b[maxn];
int sk[maxn], top;
int x;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		if(x + top < a[i] - 1) return printf("-1"), 0;
		if(a[i] == x + 1){
			b[i] = ++x;
		}else if(a[i] == x){
			sk[++top] = i;
		}else{
			b[i] = ++x;
			while(x < a[i]){
				b[sk[top--]] = ++x;
			}
		}
	}
	while(top) b[sk[top--]] = 1e6;
	for(int i = 1;i <= n;i++) printf("%d ", b[i] - 1);
}