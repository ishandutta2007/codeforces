#include <algorithm>
#include <cstring> 
#include <cstdio>
#include <set>
#define int long long

using std::min;
using std::max;

std::set<int>vec[320][3];
int q,n=100000,pos[100001],block=316,ans[100001],up[100001],down[100001],cnt[320],uptot[320],downtot[320];
int upsorted[320][320],downsorted[320][320];
long long upsum[320][320],downsum[320][320],inf=100000000000ll;
long long stat[100010];
void rebuild(int x){
	int tem=(x-1)*block;
	for(int i=tem+1;pos[i]==x;i++)
		  upsorted[x][i-tem]=(stat[i]==3?up[i]  :inf),
		downsorted[x][i-tem]=(stat[i]==3?down[i]:inf);
	std::sort(  upsorted[x]+1,  upsorted[x]+block+1);
	std::sort(downsorted[x]+1,downsorted[x]+block+1);
	for(int i=1;i<=block;i++)
		  upsum[x][i]=  upsum[x][i-1]+  upsorted[x][i],
		downsum[x][i]=downsum[x][i-1]+downsorted[x][i];
}
signed main(){
	scanf("%I64d",&q);
	for(int i=1;i<=n;i++)vec[pos[i]=((i-1)/block+1)][0].insert(i);
	for(int i=1;i<=n;i++)up[i]=down[i]=inf;
	for(int i=1;i<=pos[n];i++){
		uptot[i]=downtot[i]=inf;
		for(int j=1;j<=block;j++)
			upsorted[i][j]=downsorted[i][j]=inf;
	}
	for(int i=1,opt,l,r,k;i<=q;i++){
		scanf("%I64d%I64d%I64d",&opt,&l,&r);
		--r;
		if(opt==1){
			scanf("%I64d",&k);
			signed tem=(k>0)?1:2;
			if(pos[l]==pos[r]){
				for(int i=l;i<=r;++i){
					if(k>0)up[i]=min(up[i],k);
					else down[i]=min(down[i],-k);
					if(!stat[i])vec[pos[i]][0].erase(i),vec[pos[i]][tem].insert(i),stat[i]=tem;
					else if(stat[i]==(3^tem))vec[pos[i]][3^tem].erase(i),++cnt[pos[l]],stat[i]=3;
				}
				rebuild(pos[l]);
			}
			else{
				for(int i=l;pos[i]==pos[l];++i){
					if(k>0)up[i]=min(up[i],k);
					else down[i]=min(down[i],-k);
					if(!stat[i])vec[pos[i]][0].erase(i),vec[pos[i]][tem].insert(i),stat[i]=tem;
					else if(stat[i]==(3^tem))vec[pos[i]][3^tem].erase(i),++cnt[pos[l]],stat[i]=3;
				}
				rebuild(pos[l]);
				for(int i=r;pos[i]==pos[r];--i){
					if(k>0)up[i]=min(up[i],k);
					else down[i]=min(down[i],-k);
					if(!stat[i])vec[pos[i]][0].erase(i),vec[pos[i]][tem].insert(i),stat[i]=tem;
					else if(stat[i]==(3^tem))vec[pos[i]][3^tem].erase(i),++cnt[pos[r]],stat[i]=3;
				}
				rebuild(pos[r]);
				for(int i=pos[l]+1;i<pos[r];++i){
					for(std::set<int>::iterator it=vec[i][0].begin();it!=vec[i][0].end();++it)
						stat[*it]=tem,vec[i][tem].insert(*it);
					vec[i][0].clear();
					for(std::set<int>::iterator it=vec[i][3^tem].begin();it!=vec[i][3^tem].end();++it)
						stat[*it]=3,++cnt[i];
					if(vec[i][3^tem].size())rebuild(i),vec[i][3^tem].clear();
					if(k>0)uptot[i]=min(uptot[i],k);
					else downtot[i]=min(downtot[i],-k);
				}
			}
		}
		else{
			long long ans=0;
			if(pos[l]==pos[r]){
				for(int i=l;i<=r;++i)if(stat[i]==3)ans+=min(uptot[pos[i]],up[i])+min(downtot[pos[i]],down[i]);
			}
			else{
				for(int i=l;pos[i]==pos[l];++i)if(stat[i]==3)ans+=min(uptot[pos[i]],up[i])+min(downtot[pos[i]],down[i]);
				for(int i=r;pos[i]==pos[r];--i)if(stat[i]==3)ans+=min(uptot[pos[i]],up[i])+min(downtot[pos[i]],down[i]);
				for(int i=pos[l]+1,P;i<pos[r];++i){
//					int tem=0;
//					for(int j=(i-1)*block+1;pos[j]==i;++j)if(stat[j]==3)ans+=min(uptot[i],up[j])+min(downtot[i],down[j]),++tem;
//					if(tem!=cnt[i])printf("%d %d\n",tem,cnt[i]);
					if(upsorted[i][cnt[i]]<=uptot[i])ans+=upsum[i][cnt[i]];
					else{
						P=std::upper_bound(upsorted[i]+1,upsorted[i]+cnt[i]+1,uptot[i])-upsorted[i]-1;
						ans+=upsum[i][P]+1ll*uptot[i]*(cnt[i]-P);
					}
					if(downsorted[i][cnt[i]]<=downtot[i])ans+=downsum[i][cnt[i]];
					else{
						P=std::upper_bound(downsorted[i]+1,downsorted[i]+cnt[i]+1,downtot[i])-downsorted[i]-1;
						ans+=downsum[i][P]+1ll*downtot[i]*(cnt[i]-P);
					}
				}
			}
			printf("%I64d\n",ans);
		}
	}
}