#include <cstdio>
#include <cstring>

int n;
char str[200005];

int t(char x){
	if(x <= 'Z' && x >= 'A') return x - 'A';
	return x - 'a';
}

int dx[200005];
int main(){
	int ret = 0;
	scanf("%s",str+1);
	int t;
	int len = (int)strlen(str+1);
	scanf("%d",&t);
	while(t--){
		int u;
		scanf("%d",&u);
		dx[u]++;
		dx[len - u + 2]--;
	}
	for(int i=1; i<=len; i++){
		dx[i] += dx[i-1];
		if(dx[i] % 2){
			putchar(str[len - i + 1]);
		}
		else putchar(str[i]);
	}
}