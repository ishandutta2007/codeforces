#include <bits/stdc++.h>
using namespace std;

int n, k, a[55];
char st[3];

void get(int x){
	if(x > 25) st[0] = 'B';
	else st[0] = 'A';
	x %= 26;
	st[1] = 'a' + x;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i < k; i++){
		get(i);
		a[i] = i;
		printf("%s ", st);
	}
	for(int i = k; i <= n; i++){
		char buf[4];
		scanf("%s", buf);
		if(buf[0] == 'Y') a[i] = i;
		else a[i] = a[i - k + 1];
		get(a[i]);
		printf("%s ", st);
	}
	puts("");
}