#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

int n,a[1000001],c[1000001],m,Xor[1000001],last[1000001],ans[1000001];
std::vector<std::pair<int,int> >vec[1000001];
std::map<int,int>map;
void update(int ind,int num){for(;ind;ind-=ind&-ind)c[ind]^=num;}
int query(int ind){int tot=0;for(;ind<=n;ind+=ind&-ind)tot^=c[ind];return tot;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),Xor[i]=a[i]^Xor[i-1],last[i]=map[a[i]],map[a[i]]=i;
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		vec[r].push_back(std::make_pair(l,i));
	}
	for(int i=1;i<=n;i++){
		update(i,a[i]);
		update(last[i],a[i]);
		for(std::vector<std::pair<int,int> >::iterator it=vec[i].begin();it!=vec[i].end();++it)
			ans[it->second]=query(it->first)^Xor[i]^Xor[it->first-1];
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}