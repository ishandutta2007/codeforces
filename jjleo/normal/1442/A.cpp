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
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int x = 0, y = a[1];
		for(int i = 2;i <= n;i++){
			if(a[i] > a[i - 1]){
				x += a[i] - a[i - 1]; 
			}else{
				y -= a[i - 1] - a[i];
			}
		}
		puts(y >= 0 ? "YES" : "NO");
	}
}