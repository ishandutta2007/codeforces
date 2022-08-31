#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

int n,a[300001],b[300001];
int f[300001],pre[300001],pos[300001];
std::vector<int>vec[300001];
std::pair<int,int>c[300010];
void update(int ind,std::pair<int,int> num){
	for(;ind;ind-=ind&-ind)c[ind]=std::min(c[ind],num);
}
std::pair<int,int> query(int ind){
	std::pair<int,int>tot=std::make_pair(0x7f7f7f7f,0);
	for(;ind<=n+1;ind+=ind&-ind)tot=std::min(tot,c[ind]);
	return tot;
}
int q[300001],h,t;
std::set<std::pair<int,int> >set;
bool vis[300001];
int stk[300001],top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i),set.insert(std::make_pair(i,i+b[i]));
	set.insert(std::make_pair(0,0));
	for(int i=0;i<=n;++i)f[i]=0x7f7f7f7f;
	h=t=0;
	q[++t]=n;
	f[n]=0;
	vis[n]=1;
	while(h<t){
		++h;
		for(;;){
			auto now=set.lower_bound(std::make_pair(q[h]-a[q[h]],-0x7f7f7f7f));
			if(now==set.end()||now->first>q[h])break;
			// printf("%d %d\n",now->first,now->second);
			auto x=*now;
			set.erase(*now);
			if(vis[x.second])continue;
			f[x.second]=f[q[h]]+1;
			pre[x.second]=q[h];
			pos[x.second]=x.first;
			q[++t]=x.second;
			vis[x.second]=1;
		}
	}
	// for(int i=0;i<=n;++i)printf("%d ",f[i]);putchar('\n');
	if(f[0]==0x7f7f7f7f)puts("-1");
	else{
		printf("%d\n",f[0]);
		for(int tem=0;tem!=n;tem=pre[tem]){
			stk[++top]=pos[tem];
		}
		for(int i=top;i;--i)printf("%d ",stk[i]);
	}
}