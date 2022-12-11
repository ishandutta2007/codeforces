#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[110000];
int m,pd[110000],n,pre[110000];
int check(int K){
	memcpy(pre,pd,sizeof pd);
	int now=1; while (now<=n&&pd[now]) now++;
	for (int i=1;i<=n;i++)
		if (ch[i]==K){
			now=max(now,i-m+1); 
			while (now<=n-m+1&&now<=i) pd[now]=1,now++;
		}
	for (int i=1;i<=n-m+1;i++) if (pd[i]==0) return 0;
	memcpy(pd,pre,sizeof pre);
	return 1;
}
void getans(int K){
	for (int i='a';i<K;i++)
		for (int j=1;j<=n;j++) if (ch[j]==i) putchar(i);
	int now=1; while (now<=n&&pd[now]) now++; int pre=0;
	for (int i=1;i<=n;i++){
		if (ch[i]==K){
			if (i-m+1>now){
				while (now<=n-m+1&&now<=pre) pd[now]=1,now++;
				while (now<=n-m+1&&pd[now]) now++;
				putchar(K);
			}
			pre=i;
		}
	}
	if (now<=n-m+1) putchar(K);
}
int main(){
	scanf("%d",&m);
	scanf("%s",ch+1); n=strlen(ch+1);
	for (int i='a';i<='z';i++)
		if (check(i)){
			getans(i);
			return 0;
		}
}