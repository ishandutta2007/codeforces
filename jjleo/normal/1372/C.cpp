#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int t;
int a[maxn];


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int gg = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int l = 1, r = n;
		while(1){
			if(a[l] == l && l < n) l++;
			else break;
		}
		if(l == n){
			puts("0");
			continue;
		}
		while(1){
			if(a[r] == r && r > 1) r--;
			else break;
		}
		for(int i = l;i <= r;i++){
			if(a[i] == i) gg++;
		}
		if(gg == n) puts("0");
		else if(gg) puts("2");
		else puts("1");
	}
}