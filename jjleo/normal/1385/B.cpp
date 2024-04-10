#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
bool tag[maxn];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) tag[i] = false;
		for(int i = 1;i <= n * 2;i++){
			scanf("%d", &x);
			if(!tag[x]){
				printf("%d ", x);
				tag[x] = true;
			}
		}
		puts("");
	}
}