#include <cstdio>

int n;
char str[200005];

int t(char x){
	if(x <= 'Z' && x >= 'A') return x - 'A';
	return x - 'a';
}

int cnt[200005];
int main(){
	int ret = 0;
	scanf("%d %s",&n,str);
	for(int i=0; str[i]; i+=2){
		cnt[t(str[i])]++;
		if(cnt[t(str[i+1])]){
			cnt[t(str[i+1])]--;
		}
		else ret++;
	}
	printf("%d",ret);
}