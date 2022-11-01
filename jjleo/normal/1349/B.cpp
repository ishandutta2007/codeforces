#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t;
int n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		bool suc1 = false, suc2 = false;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(a[i] == k) suc2 = true;
			if(a[i] >= k && a[i - 1] >= k){
				suc1 = true;
			}
			if(a[i] > 1 && a[i] >= k && a[i - 2] >= k){
				suc1 = true;
			}
	 	}
	 	if(n == 1 && a[1] == k) suc1 = suc2 = true;
		puts(suc1 && suc2 ? "yes" : "no");
	}
}