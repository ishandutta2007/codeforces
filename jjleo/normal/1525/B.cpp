#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(i ^ a[i]) tag = true;
		}
		if(!tag){
			puts("0");
			continue;
		}
		if(a[1] == 1 || a[n] == n) puts("1");
		else if(a[1] == n && a[n] == 1) puts("3");
		else puts("2");
	}
}