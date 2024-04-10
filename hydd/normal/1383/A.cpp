/*********************************************************************
	Problem:
	Author:hydd
	Date:
*********************************************************************/
#include<cstdio>
#include<algorithm>
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int T,n,ans,num[1100000];
char s[1100000],t[1100000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		ans=0;
		for (int j=1;j<=n;j++)
			if (s[j]>t[j]){ ans=-1; break;}
		if (ans==-1){
			puts("-1");
			continue;
		}
		for (int i='a';i<='t';i++){
			int c=false,tmp='z';
			for (int j=1;j<=n;j++)
				if (s[j]==i&&t[j]!=i){
					c=true;
					tmp=min(tmp,(int)t[j]);
				}
			if (!c) continue;
			ans++;
			for (int j=1;j<=n;j++)
				if (s[j]==i&&t[j]!=i) s[j]=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}