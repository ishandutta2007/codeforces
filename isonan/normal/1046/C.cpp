#include <cstdio>

int n,d,s[200001],p[200001],l,r,mid,ans;
bool judge(int u){
	for(int i=1;i<=u;i++)
		if(p[n-i+1]+s[d-u-1+i]>s[d]+p[1])return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	l=1,r=d;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(d-mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}