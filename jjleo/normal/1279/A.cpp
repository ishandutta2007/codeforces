#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a[3];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 0;i < 3;i++) scanf("%d", &a[i]);
		sort(a, a + 3);
		if(a[0] + a[1] >= a[2] - 1) puts("Yes");
		else puts("No");
		
	}
}