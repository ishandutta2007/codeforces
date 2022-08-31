#include <cstdio>
#include <algorithm>
using namespace std;

char str[200010];
int n,f[200010],g[200010],ans,tot;
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++){
		f[i]=(str[i]=='G')?(f[i-1]+1):0;
		if(str[i]=='G')tot++;
		ans=max(ans,f[i]);
	}
	for(int i=n;i;i--){
		g[i]=str[i]=='G'?g[i+1]+1:0;
	}
	for(int i=1;i<=n;i++){
		if(str[i]=='S'&&str[i-1]=='G'&&str[i+1]=='G'&&i>1&&i<n){
			if(f[i-1]+g[i+1]==tot)ans=max(ans,tot);
			else ans=max(ans,f[i-1]+g[i+1]+1);
		}
		if(tot!=f[i])ans=max(ans,f[i]+1);
	}
	printf("%d",ans);
}