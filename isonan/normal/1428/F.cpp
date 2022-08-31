#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int n,cnt[500010],top;
long long sum[500010];
long long ans;
char str[500001];
long long gsum(long long l,long long r){
	return ((r-l+1)*(l+r))>>1ll;
}
long long query(int x){
	if(!x)return sum[x];
//	printf("%lld %lld\n",,top);
//	printf("query %d %lld\n",x,1ll*cnt[std::min(x-1,top)]*x+((x>top)?0ll:sum[x]));
	return 1ll*cnt[std::min(x-1,top)]*x+((x>top)?0ll:sum[x]);
}
void solve(int l,int r){
	if(l==r){
		ans+=(str[l]=='1');
		return;
	}
	int mid=(l+r)>>1,far=-1;
	memset(cnt,0,(r-l+2)<<3);
	memset(sum,0,(r-l+2)<<3);
	top=r-l+1;
	bool cross=(str[mid]==str[mid+1]&&str[mid]=='1');
	for(int i=mid+1,now=0,mx=0;i<=r;i++){
		if(str[i]=='1'){
			++now;
			mx=std::max(mx,now);
		}
		else{
			now=0;
			if(!~far)far=i;
		}
		if((!cross)||~far){
			++cnt[mx];
			sum[mx]+=mx;
		}
	}
	if(!~far)far=r+1;
	--far;
//	for(int i=1;i<=r-l+1;i++)printf("%d %d\n",cnt[i],sum[i]);
	for(int i=r-l;~i;--i)sum[i]+=sum[i+1];
	for(int i=1;i<=r-l+1;i++)cnt[i]+=cnt[i-1];
	if(cross){
//		printf("%d %d %d\n",l,r,far);
		for(int i=mid,now=0,f=-1,mx=0;i>=l;i--){
			if(str[i]=='1'){
				++now;
				mx=std::max(mx,now);
			}
			else{
				now=0;
				if(!~f)f=i+1;
			}
			if(!~f){
				ans+=gsum(mid+1,far)+1ll*(far-mid)*(1ll-i);
//				printf("%d %d\n",i,ans);
			}
			else{
				ans+=std::max(std::min(mx+f-1,far)-1ll*(mid+1)+1,0ll)*mx;
				int l=std::max(mid+1,mx+f);
				if(l<=far)ans+=gsum(l,far)+1ll*(far-l+1)*(1-f);
			}
			if(~f)ans+=query(std::max(mx,far-f+1));
			else ans+=query(std::max(mx,far-i+1));
//			printf("%d %d %d %lld %lld\n",i,ans,std::max(mx,far-f+1));
		}
	}
	else{
		for(int i=mid,now=0,f=-1,mx=0;i>=l;i--){
			if(str[i]=='1'){
				++now;
				mx=std::max(mx,now);
			}
			else{
				now=0;
			}
			ans+=query(mx);
		}
	}
//	printf("solve %d %d %lld\n",l,r,ans);
	solve(l,mid);
	solve(mid+1,r);
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	scanf("%s",str+1);
	solve(1,n);
	printf("%lld\n",ans);
}