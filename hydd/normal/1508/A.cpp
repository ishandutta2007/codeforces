#include<bits/stdc++.h>
using namespace std;
int T,n,pos[4],tot[2];
char s[4][210000],Ans[310000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int k=1;k<=3;k++){
			scanf("%s",s[k]+1);
			pos[k]=1;
		}
		int len=0;
		while (len<n+n+n&&pos[1]<=n+n&&pos[2]<=n+n&&pos[3]<=n+n){
			tot[0]=0; tot[1]=0;
			tot[s[1][pos[1]]-'0']++;
			tot[s[2][pos[2]]-'0']++;
			tot[s[3][pos[3]]-'0']++;
			char now=(tot[0]<tot[1])+'0'; Ans[++len]=now;
			if (s[1][pos[1]]==now) pos[1]++;
			if (s[2][pos[2]]==now) pos[2]++;
			if (s[3][pos[3]]==now) pos[3]++;
		}
		int op;
		if (pos[1]>n+n) op=(pos[2]>pos[3]?2:3);
		else if (pos[2]>n+n) op=(pos[1]>pos[3]?1:3);
		else op=(pos[1]>pos[2]?1:2);
		while (pos[op]<=n+n) Ans[++len]=s[op][pos[op]],pos[op]++;
		while (len<n+n+n) Ans[++len]='0';
		Ans[3*n+1]=0; printf("%s\n",Ans+1);
	}
	return 0;
}