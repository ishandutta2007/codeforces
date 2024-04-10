#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int r[maxn], b[maxn];
int sum, ans = 1;
int c;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &r[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	for(int i = 1;i <= n;i++){
		if(r[i] > b[i]) ++sum;
		else if(b[i] > r[i]) ++ans;
	}
	if(!sum) return printf("-1"), 0;
	printf("%d", ans / sum + (ans % sum != 0));
}