#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
int a[maxn];
int b[maxn];


int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++){
		printf("XOR %d %d\n", i, i - 1);
		fflush(stdout);
		scanf("%d", &a[i]);
	}
	int x = 0, y = 0;
	memset(b, -1, sizeof(b));
	for(int i = 1;i <= n;i++){
		a[i] ^= a[i - 1];
		if(x) continue;
		if(~b[a[i]]){
			x = i, y = b[a[i]];
			continue;
		}
		b[a[i]] = i;
	}
	//printf("%d %d--\n", x, y);
	if(x){
		printf("OR %d %d\n", x, y);
		fflush(stdout);
		scanf("%d", &y);
		for(int i = 1;i < n;i <<= 1){
			if((a[x] ^ y) & i) a[1] |= i;
		}
	}else{
		printf("OR %d %d\n", b[n - 1], b[n - 2]);
		fflush(stdout);
		scanf("%d", &x);
		for(int i = 2;i < n;i <<= 1){
			if(!(x & i)) a[1] |= i;
		}
		printf("OR %d %d\n", b[1], b[3]);
		fflush(stdout);
		scanf("%d", &x);
		if(!(x & 1)) a[1] |= 1;
	}
	printf("! ");
	for(int i = 1;i <= n;i++) printf("%d ", i == 1 ? a[1] : (a[i] ^ a[1]));
	puts("");
}