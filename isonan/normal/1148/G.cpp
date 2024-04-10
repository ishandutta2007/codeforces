#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <map>

std::map<long long,int>map;
int n,k,a[100001],num[100001];
int cnt[10000001],prime[10000001],mu[10000001],top,un;
long long hash[10000001],val[100001];
bool pri[10000001],bad[100001],vis[100001];
std::vector<int>vec[100001],d[100001];
void init(int x){
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=x;i++)
		if(!bad[i])
			for(int j=0;j<d[i].size();j++)
				++cnt[d[i][j]];
}
std::vector<int>f(int c){
	init(c);
	std::vector<int>tem;
	for(int i=1;i<=c;i++)
		if(!bad[i]){
			int cnt=0;
			for(int j=0;j<d[i].size();j++)
				cnt+=mu[d[i][j]]*::cnt[d[i][j]];
			if(cnt)tem.push_back(i);
		}
	return tem;
}
void dfs(int i,int x,int val){
	if(x==vec[i].size()){
		d[i].push_back(val);
		return;
	}
	dfs(i,x+1,val);
	dfs(i,x+1,val*vec[i][x]);
}
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i),num[i]=i;
		int tem=a[i];
		for(int j=2;1ll*j*j<=tem;j++)
			if(tem%j==0){
				while(tem%j==0)tem/=j;
				vec[i].push_back(j);
			}
		if(tem>1)vec[i].push_back(tem);
		dfs(i,0,1);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<63;j++)
			if(rand()%2)val[i]|=1ull<<(unsigned long long )j;
		map[val[i]]=i;
	}
	mu[1]=1;
	for(int i=2;i<=10000000;i++){
		if(!pri[i])prime[++top]=i,mu[i]=-1;
		for(int j=1;j<=top&&i*prime[j]<=10000000;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<d[i].size();j++)
			++cnt[d[i][j]],hash[d[i][j]]^=val[i];
	bool cando=0;
	int tem=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=0;j<d[i].size();j++)
			cnt+=mu[d[i][j]]*::cnt[d[i][j]];
//		printf("%d %d\n",i,cnt);
		if(cnt>=2){
			int p1=0,p2=0;
			for(int j=1;j<=n;j++)
				if(gcd(a[i],a[j])==1){
					if(!p1)p1=j;
					else{
						p2=j;
						break;
					}
				}
			bad[i]=bad[p1]=bad[p2]=1;
			un=p1;
			cando=1;
			break;
		}
		else if(cnt==1){
			vis[i]=1;
			long long tem=0;
			for(int j=0;j<d[i].size();j++)
				tem^=hash[d[i][j]];
			vis[map[tem]]=0;
		}else vis[i]=1;
	}
	if(!cando){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(vis[i]){
				printf("%d ",i);
				++cnt;
				if(cnt==k)break;
			}
	}
	else{
		std::vector<int> tem=f(n);
		if(n-tem.size()-3>=k){
			for(int i=0;i<tem.size();i++)
				bad[tem[i]]=1;
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(!bad[i]){
					printf("%d ",i);
					cnt++;
					if(cnt==k)break;
				}
		}
		else{
			int l=0,r=n,mid,Ans=-1;
			std::vector<int>ans;
			while(l<=r){
				mid=(l+r)>>1;
				tem=f(mid);
				if(tem.size()+3<k)Ans=mid,ans=tem,l=mid+1;
				else r=mid-1;
			}
			int cnt=ans.size()+3;
			if(~Ans){
				tem=f(Ans+1);
				if(tem.size()+3==k){
					for(int i=0;i<tem.size();i++)bad[tem[i]]=1;
					for(int i=1;i<=n;i++)if(bad[i])printf("%d ",i);
					return 0;
				}
				for(int i=0;i<ans.size();i++)bad[ans[i]]=1;
				if(k-cnt==1){
					bad[un]=0;
					--cnt;
				}
				bad[Ans+1]=1;
				++cnt;
				for(int i=1;i<=Ans;i++){
					if(!bad[i]&&gcd(a[i],a[Ans+1])==1){
						++cnt;
						bad[i]=1;
						if(cnt==k)break;
					}
				}
			}
			for(int i=1;i<=n;i++)if(bad[i])printf("%d ",i);
		}
	}
}