#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int t,m;
long long n,a[400010],k;
std::vector<std::pair<long long,long long> >vec;
signed main(){
	scanf("%I64d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		for(int i=1;i<=m;i++)scanf("%I64d",a+i);
		a[m+1]=n-a[m];
		for(int i=m;i;i--)a[i]-=a[i-1];
		++m;
//		for(int i=1;i<=m;i++)printf("%lld ",a[i]);putchar('\n');
		long long L=-1,R=-1,pL,pR;
		long long l=1,r=n,mid;
		for(int i=1;i<=m;i++)r=std::min(r,a[i]);
		while(l<=r){
			mid=(l+r)>>1;
			long long cnt=0;
			for(int i=1;i<=m;i++)cnt+=(a[i]/mid)-1;
			if(cnt>=k)L=mid,l=mid+1;
			else r=mid-1;
		}
		l=1,r=n;
		while(l<=r){
			mid=(l+r)>>1;
			long long cnt=0;
			for(int i=1;i<=m;i++)cnt+=(a[i]+mid-1)/mid-1;
			if(cnt<=k)R=mid,r=mid-1;
			else l=mid+1;
		}
//		printf("%lld %lld\n",L,R);
		pL=L,pR=R;
		vec.clear();
		for(int i=1;i<=m;i++){
			long long l=(a[i]/L),r=(a[i]+R-1)/R;
			if(l<r){
				vec.push_back(std::make_pair((a[i])/r,(a[i]+l-1)/l));
			}
//			printf("%lld %lld %lld %lld %lld\n",a[i],l,r,pL,pR);
		}
		vec.push_back(std::make_pair(L,R));
		std::sort(vec.begin(),vec.end());
		long long ans=1e18,mx=R;
		for(int i=0;i<vec.size();i++){
			ans=std::min(ans,mx-vec[i].first);
			mx=std::max(mx,vec[i].second);
		}
//		printf("%lld %lld\n",pL,pR);
		printf("%I64d\n",ans);
	}
}