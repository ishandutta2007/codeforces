#include <cstdio>
#include <vector>

int st[300001][21],loga[300001],n,ansp[300001],top,lastt;
std::vector<int>pos[1000001];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
void judge(int u){
	int k=loga[u];
	top=0;
	for(int i=1;i+u-1<=n;i++){
		int ansg=gcd(st[i][k],st[i+u-(1<<k)][k]);
		auto x=std::lower_bound(pos[ansg].begin(),pos[ansg].end(),i);
		if(x!=pos[ansg].end()&&*x<i+u)ansp[++top]=i;
	}
}
int main(){
	scanf("%d",&n);
	loga[0]=-1;
	for(int i=1;i<=n;i++)loga[i]=loga[i>>1]+1;
	for(int i=1;i<=n;i++)scanf("%d",&st[i][0]),pos[st[i][0]].push_back(i);
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int l=1,r=n,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		judge(mid);
		if(top)ans=mid,lastt=top,l=mid+1;
		else r=mid-1;
	}
	printf("%d %d\n",lastt,ans-1);
	for(int i=1;i<=lastt;i++)printf("%d ",ansp[i]);
}