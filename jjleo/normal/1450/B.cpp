#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int x[maxn], y[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
		bool suc = false;
		for(int i = 1;i <= n;i++){
			bool tag = false;
			for(int j = 1;j <= n && !tag;j++){
				if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) tag = true;
			}
			if(!tag){
				suc = true;
				break;
			}
		}
		puts(suc ? "1" : "-1");
	}
}