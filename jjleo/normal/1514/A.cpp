#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(tag) continue;
			int y = x;
			for(int j = 2;j * j <= x;j++){
				int cnt = 0;
				while(y % j == 0) y /= j, cnt++;
				if(cnt & 1){
					tag = true;
					break;
				}
			}
			if(y ^ 1) tag = true;
		}
		puts(tag ? "YES" : "NO");
	}
}