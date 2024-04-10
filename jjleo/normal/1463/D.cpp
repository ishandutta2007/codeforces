#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n;
int a[maxn], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= 2 * n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = 1;
		int l = 0, r = 0;
		x = 0;
		for(int i = 1;i <= 2 * n;i++){
			if(a[i]) x++;
			else if(x) x--, l++;
		}
		x = 0;
		for(int i = 1;i <= 2 * n;i++){
			if(!a[i]) x++;
			else if(x) x--, r++;
		}
		r = n - r;
		printf("%d\n", abs(r - l) + 1);
	}
}