#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[1100000];//total of edge (i,i+1)
char s[510000];
void init(){
	int now=n;
	for (int i=1;i<=n;i++){
		if (s[i]=='0') cnt[now]++,now++;
		if (s[i]=='1') now--,cnt[now]++;
	}
}
void work(){
	int now=n;
	for (int i=1;i<=n;i++){
		if (cnt[now]>1||cnt[now]==1&&!cnt[now-1]) putchar('0'),cnt[now]--,now++;
		else putchar('1'),now--,cnt[now]--;
	}
	putchar('\n');
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1); n=strlen(s+1);
		init(); work();
	}
	return 0;
}