#include<bits/stdc++.h>
using namespace std;
int n;
char s[105];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s);
		int l=-1,r=n;
		for(int i=0;i<n;++i)if(s[i]=='>'){l=i;break;}
		for(int i=n-1;~i;--i)if(s[i]=='<'){r=i;break;}
		int ans=n-1;
		if(l>=0)ans=min(ans,l);
		if(r<n)ans=min(ans,n-r-1);
		printf("%d\n",ans);
	}
	return 0;
}