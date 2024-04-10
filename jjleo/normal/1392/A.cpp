#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool tag = false;
		for(int i = 2;i <= n;i++){
			if(a[i] != a[i - 1]){
				tag = true;
				break;
			}
		}
		printf("%d\n", tag ? 1 : n);
	}
}