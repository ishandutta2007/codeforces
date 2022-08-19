#include <cstdio>
#include <vector>
#include <map>
#define int long long

long long mn=1,M=10004205361450474;
const int MM=10004205361450474;
long long map[5][10001];
int cnt=0;
long long f(long long a,int b){
	a=std::min(a,10000ll);
	// printf("f %lld %lld\n",a,b);
	if(!b)return 0;
	if(b==1)return a;
	long long &p=map[b][a];
	if(p)return p;
	long long now=a;
	for(int i=1;i<=a+1;++i){
		now+=f(now,b-1)+1;
		// printf("%lld\n",now);
	}
	// printf("f[%lld][%lld]=%lld\n",a,b,now-a-1);
	return p=now-a-1;
}
int Query(std::vector<long long>&vec){
	printf("%lld ",vec.size());
	for(int i=0;i<vec.size();++i)printf("%lld ",vec[i]);putchar('\n');
	fflush(stdout);
	int ans;
	scanf("%lld",&ans);
	return ans;
}
long long x;
int MyQuery(std::vector<long long>&vec){
	for(int i=0;i<vec.size();++i)
		if(vec[i]==x)return -1;
	for(int i=0;i<vec.size();++i)
		if(vec[i]>x)return i;
	return vec.size();
}
signed main(){
	// scanf("%lld",&x);
	for(int i=1;i<=5;++i){
		std::vector<long long>que;
		long long now=mn;
		for(int j=1;j<=std::min(mn,10000ll);++j){
			long long Len=f(std::min(now,10000ll),5-i);
			now=std::min(now+Len,M);
			if(que.empty()||que.back()!=now)que.push_back(now);
			if(now<M)++now;
		}
		int ans=Query(que);
		// printf("%lld %lld\n",now,ans);
		if(ans==-1)return 0;
		else{
			// printf("%lld %lld\n",ans,que.size());
			long long l=(ans==0)?mn:(que[ans-1]+1),r=(ans==que.size())?M:(que[ans]-1);
			mn=std::max(mn,l);
			M=std::min(M,r);
		}
		// printf("%lld %lld\n",mn,M);
	}
}