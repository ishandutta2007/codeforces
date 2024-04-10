#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int pa[maxn],pb[maxn];
int t[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;i++)pa[read()]=i;
	for(int i=1;i<=n;i++)pb[read()]=i;
	for(int i=1;i<=n;i++){
		if(pb[i]>=pa[i])ans=max(ans,++t[pb[i]-pa[i]]);
		else ans=max(ans,++t[pb[i]-pa[i]+n]);
	}
	printf("%d\n",ans);
	return 0;
}