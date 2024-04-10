#include <queue>
#include <cstdio>
#include <algorithm>

int T,top;
long long pri[51],dis[100001];
std::queue<int>q;
int h,t,tem[51],prime[40000001],Top;
bool Pri[40000001];
bool inq[100001];
bool ans[10001];
int qsm(int a,int b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
struct point{
	long long n,k;
	int ord;
}num[10001];
bool cmp(point a,point b){
	return a.k<b.k;
}
int main(){
	for(int i=2;i<=40000000;i++){
		if(!Pri[i])prime[++Top]=i;
		for(int j=1;j<=Top&&i*prime[j]<=40000000;j++){
			Pri[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		long long n,k;
		scanf("%lld%lld",&n,&k);
		num[fd]=(point){n,k,fd};
	}
	std::sort(num+1,num+T+1,cmp);
	for(int fd=1;fd<=T;fd++){
		if(num[fd].k!=num[fd-1].k&&num[fd].k!=1){
			top=0;
			long long tem=num[fd].k;
			for(int i=1;i<=Top&&1ll*prime[i]*prime[i]<=tem;i++)
				if(tem%prime[i]==0){
					pri[++top]=prime[i];
					while(tem%prime[i]==0)tem/=prime[i];
				}
			if(tem>1)pri[++top]=tem;
//			for(int i=1;i<=top;i++)printf("%lld ",pri[i]);putchar('\n');
			if(pri[1]<=100000){
				for(int i=2;i<=top;i++)::tem[i]=pri[i]%pri[1];
				for(int i=1;i<pri[1];i++)dis[i]=1e18;
				dis[0]=0;
				q.push(0);
				inq[0]=1;
				while(!q.empty()){
					int now=q.front();
					q.pop();
					inq[now]=0;
					for(int j=2;j<=top;j++){
						int u=(1ll*now+::tem[j]);
						if(u>=pri[1])u-=pri[1];
						if(dis[u]>dis[now]+pri[j]){
							dis[u]=dis[now]+pri[j];
							if(!inq[u])q.push(u),inq[u]=1;
						}
					}
				}
			}
		}
		if(num[fd].k==1)continue;
		bool &Ans=ans[num[fd].ord];
		long long n=num[fd].n;
		if(pri[1]<=100000)Ans=(dis[n%pri[1]]<=n);
		else if(top==1)Ans=(n%pri[1]==0);
		else{
			int u=1ll*(n%pri[1])*qsm(pri[2]%pri[1],pri[1]-2,pri[1])%pri[1];
			Ans=(1ll*pri[2]*u<=n);
		}
	}
	for(int fd=1;fd<=T;fd++)puts(ans[fd]?"YES":"NO");
}