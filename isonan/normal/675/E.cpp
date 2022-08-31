#include <cstdio>
#include <map>
using std::max;

int st[100001][21],n,loga[100001];
std::map<std::pair<int,int>,long long>map;
int query(int l,int r){
	int k=loga[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
long long f(int l,int r){
	if(r==n)return 0;
	if(map.count(std::make_pair(l,r)))return map[std::make_pair(l,r)];
	return map[std::make_pair(l,r)]=n-r+f(r+1,query(l,r));
}
int main(){
	scanf("%d",&n);
	loga[0]=-1;
	for(int i=1;i<=n;i++)loga[i]=loga[i>>1]+1;
	for(int i=1;i<n;i++)scanf("%d",&st[i][0]);
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	long long ans=0;
	for(int i=1;i<n;i++)ans+=f(i,i);
	printf("%I64d",ans);
}