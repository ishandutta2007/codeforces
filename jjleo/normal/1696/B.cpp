#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(*max_element(a + 1, a + 1 + n) == 0){
			puts("0");
			continue;
		}
		int l = 1, r = n;
		while(a[l] == 0) l++;
		while(a[r] == 0) r--;
		if(*min_element(a + l, a + 1 + r)){
			puts("1");
			continue;
		}
		puts("2");
	}
}