#include <cstdio>
#include <vector>
#include <algorithm>

int n,k;
std::vector<int>vec[3001];//,tem[3001];
int siz[3001];
long long v[3001];
//int num[3001];
//bool cmp(int a,int b){
//	return vec[a][0]>vec[b][0];
//}
long long f[3010][3001];
void add(long long *a,int s,long long v){
	for(int i=k;i>=s;i--)a[i]=std::max(a[i],a[i-s]+v);
}
void solve(int l,int r){
	if(l==r){
		long long v=0;
		for(int i=0;i<vec[l].size()&&i+1<=k;i++){
			v+=vec[l][i];
			f[l][i+1]=v;
		}
		siz[l]=vec[l].size();
		::v[l]=v;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	for(int i=mid+1;i<=r;i++)add(f[l],siz[i],v[i]);
	for(int i=mid;i>=l;i--)add(f[mid+1],siz[i],v[i]);
	for(int i=0;i<=k;i++)f[l][i]=std::max(f[l][i],f[mid+1][i]);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int tem;
		scanf("%d",&tem);
		vec[i].resize(tem);
		for(int j=0;j<tem;j++)vec[i][j]=read();
	}
	solve(1,n);
	printf("%lld\n",f[1][k]);
}