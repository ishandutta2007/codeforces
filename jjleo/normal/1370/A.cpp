#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n;
int p[maxn], cnt, num[maxn];

int main(){
	scanf("%d", &t);
	for(int i = 2;i < maxn;i++){
		if(!num[i]) num[i] = 1, p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i < maxn;j++){
			num[p[j] * i] = i;
			if(i % p[j] == 0) break;
		}
	}
	
	for(int i = 3;i < maxn;i++) num[i] = max(num[i], num[i - 1]);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", num[n]);
	}
}