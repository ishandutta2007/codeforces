#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, s;

int main(){
	scanf("%d%d", &n, &s);
	if(n == 1){
		if(s != 1){
			printf("YES\n%d\n%d", s, s - 1);
		}else{
			printf("NO");
		}
		return 0;
	}
	int x = (s + 1) / 2 + 1;
	if(s - x >= n - 1){
		printf("YES\n%d ", x);
		for(int i = 1;i < n - 1;i++) printf("1 ");
		printf("%d\n%d", s - x - (n - 2), x - 1);
	}else{
		printf("NO");
	}
}