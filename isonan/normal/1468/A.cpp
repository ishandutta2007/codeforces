#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int t,n,a[500010],orig[500010],f[500010],top,Stk[500010],Top;
std::vector<int>Do[500010];
int c[500010];
void update(int ind,int num){
	for(;ind;ind-=ind&-ind)c[ind]=std::max(c[ind],num);
}
int query(int ind){
	int tot=-0x7f7f7f7f;
	for(;ind<=top;ind+=ind&-ind)tot=std::max(tot,c[ind]);
	return tot;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		memset(c,-0x7f7f7f7f,(n+1)<<2);
		for(int i=1;i<=n;i++)scanf("%d",a+i),orig[i]=a[i],Do[i].clear();
		std::sort(orig+1,orig+n+1);
		top=std::unique(orig+1,orig+n+1)-orig-1;
		Top=0;
		for(int i=1;i<=n;i++)
			a[i]=std::lower_bound(orig+1,orig+top+1,a[i])-orig;
		for(int i=n;i;i--){
			f[i]=1;
//			printf("%d %d\n",i,Stk[Top]);
			while(Top&&a[Stk[Top]]<=a[i])--Top;
			if(Top)Do[Stk[Top]+1].push_back(i);
			Stk[++Top]=i;
		}
		int ans=1;
		for(int i=n;i;i--){
			f[i]=std::max(f[i],query(a[i])+1);
			update(a[i],f[i]);
			for(int j=0;j<Do[i].size();j++)
				f[Do[i][j]]=std::max(f[Do[i][j]],query(a[Do[i][j]])+2);
			ans=std::max(ans,f[i]+(i>1));
		}
		printf("%d\n",ans);
	}
}