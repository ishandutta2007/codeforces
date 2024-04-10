#include<bits/stdc++.h>
using namespace std;
int T,n,k,x,ans;
int cnt,p[110000];
char s[110000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		cnt=0; ans=0; x=0;
		for (int i=1;i<=n;i++)
			if (s[i]=='W'){
				if (x) p[++cnt]=i-x-1;
				ans++; x=i;
			}
		if (!ans){
			if (!k) puts("0");
			else printf("%d\n",2*k-1);
			continue;
		}
		k=min(k,n-ans);
		sort(p+1,p+cnt+1); ans+=2*k;
		for (int i=1;i<=cnt;i++)
			if (p[i]<=k){
				k-=p[i];
				ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}