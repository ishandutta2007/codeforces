#include <set>
#include <cstdio>
#include <algorithm>
using std::min;
using std::max;

std::multiset<int>S;
int n,m,k,x,stk[3001][3001],top[3001],pos[6001];
long long ans,cnt=0;
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&k);
	for(int i=1,a,b;i<=x;i++)scanf("%d%d",&a,&b),stk[a][++top[a]]=b;
	for(int i=1;i<=n;i++){
		cnt=0;
		S.clear();
		for(int j=1;j<=k+1;j++)S.insert(0),S.insert(m+1);
		for(int j=i;j<=n;j++,ans+=cnt)
			for(int K=1;K<=top[j];K++){
				auto L=S.insert(stk[j][K]),r=L;
				for(int l=k;~l;--l)pos[l]=*(L--);
				for(int l=k+1;l<=2*k;l++)pos[l]=*(++r);
				for(int l=k;l<2*k;l++)cnt+=(pos[l+1]-pos[l])*(pos[l-k+1]-pos[l-k]);
			}
	}
	printf("%I64d",ans);
}