#include <cstdio>
#include <set>

int t,n,p[100010],pos[100010],f[100010],cnt[100010];
std::multiset<int>set;
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		set.clear();
		for(int i=1;i<=n;i++)scanf("%d",p+i),pos[p[i]]=i,cnt[i]=1,set.insert(1),f[i]=0;
		f[n+1]=0;
		bool cando=1;
		for(int i=1;i<=n;i++){
			if(*set.rbegin()!=cnt[pos[i]]){
				cando=0;
				break;
			}
			set.erase(set.find(cnt[pos[i]]));
			if(pos[i]<n){
				int v=find(pos[i]+1);
				if(v<=n)set.erase(set.find(cnt[v]));
				cnt[v]+=cnt[pos[i]];
				if(v<=n)set.insert(cnt[v]);
			}
			f[pos[i]]=find(pos[i]+1);
		}
		if(cando)puts("Yes");
		else puts("No");
	}
}