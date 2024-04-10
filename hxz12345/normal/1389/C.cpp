#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
char S[1001010];
long long flag,Testing,len,fre[1001010],i,up,now,G[1001010];
int main() {
	int Testing=read();
	for (;Testing;Testing--){
		scanf("%s",S+1);len=strlen(S+1);
		for (i=0;i<=9;i++) fre[i]=0;
		for (i=1;i<=len;i++) fre[S[i]-'0']++;
		up=0;for (i=0;i<=9;i++) if (fre[i]>up) up=fre[i];
		now=len-up;
		for (G[0]=0;G[0]<=9;G[0]++)
		    for (G[1]=0;G[1]<=9;G[1]++){
		    	flag=0;up=0;
		    	for (i=1;i<=len;i++)
		    	    if (S[i]-'0'==G[flag])
		    	        up++,flag=1-flag;
		    	now=min(now,len-up/2*2);
			}
		printf("%lld\n",now);
	}
    return 0;
}