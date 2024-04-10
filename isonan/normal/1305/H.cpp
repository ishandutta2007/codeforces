#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int n,m,Q;
long long T;
std::vector<int>req,l,r;
std::vector<int> fill(std::vector<int>&req){
//	printf("fill ");
//	for(int i=1;i<=m;i++)printf("%d ",req[i]);putchar('\n');
	std::vector<int>ans(m+1);
	long long tem=T;
	for(int i=m;i;i--){
		ans[i]=0;
		if(i<m)ans[i]=ans[i+1];
		if(~req[i])ans[i]=req[i];
		tem-=ans[i];
	}
	if(tem<0)return std::vector<int>();
	for(int i=m,last=m+1;tem&&~i;i--){
		if(~req[i]){
			long long mx=(i<m)?(last-1-i)*(req[i]-ans[i+1]):0;
//			printf("%lld\n",mx);
			if(mx<=tem){
				for(int j=i+1;j<last;j++)ans[j]=req[i];
				tem-=mx;
			}
			else{
				for(int j=i+1;j<last;j++)ans[j]+=(tem/(last-1-i))+((tem%(last-1-i))>=(j-i));
				tem=0;
			}
			last=i;
		}
	}
//	for(int i=1;i<=m;i++)printf("%d ",ans[i]);putchar('\n');
//	printf("%lld\n",tem);
	if(tem)return std::vector<int>();
	return ans;
}
int q[100001],h,t;
bool check(std::vector<int> a,std::vector<int> b){
	int n=(int)a.size()-1,m=(int)b.size()-1;
//	printf("%d %d\n",n,m);
//	printf("check %d %d\n",n,m);
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
//	for(int i=1;i<=m;i++)printf("%d ",b[i]);putchar('\n');
	h=t=0;
	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	for(int i=2;i<=m;i++)b[i]+=b[i-1];
	for(int i=1;i<=n;i++)a[i]-=1ll*i*m;
	for(int i=1;i<=m;i++)b[i]-=1ll*i*n;
	for(int i=1;i<=m;i++){
		while(h<t-1&&(1ll*(b[q[t]]-b[i])*(q[t]-q[t-1])>=1ll*(b[q[t-1]]-b[q[t]])*(i-q[t])))--t;
		q[++t]=i;
	}
	for(int i=1;i<=n;i++){
		while(h<t-1&&(b[q[t]]+q[t]*i)>=(b[q[t-1]]+q[t-1]*i))--t;
		if(b[q[t]]+q[t]*i<a[n]-a[i])return 0;
	}
//	puts("good");
	return 1;
}
bool judge(int x,int y=-1){
	std::vector<int>Req=req;
	if(~y){
		for(int i=1;i<=x;i++)Req[i]=y;
	}
	std::vector<int>now=fill(Req);
	if(now.empty())return 0;
//	putchar('*');
	if(now[1]!=now[x]){
		for(int i=1;i<=x;i++)
			if(~req[i]&&req[i]!=now[1])return 0;
		for(int i=1;i<=x;i++)Req[i]=now[1];
		now=fill(Req);
		if(now.empty())return 0;
	}
	std::reverse(now.begin()+1,now.end());
	return check(l,now)&check(now,r);
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld%lld",&n,&m);
	l.resize(n+1),r.resize(n+1);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
	std::sort(l.begin()+1,l.end());
	std::sort(r.begin()+1,r.end());
	req.resize(m+1);
	for(int i=1;i<=m;i++)req[i]=-1;
	req[0]=0x7f7f7f7f;
	scanf("%lld",&Q);
	for(int i=1,a,b;i<=Q;i++){
		scanf("%lld%lld",&a,&b);
		req[a]=b;
	}
	scanf("%lld",&T);
	int l=1,r=m,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
//	return 0;
	if(!~ans){
		printf("-1 -1");
		return 0;
	}
	for(int i=1;i<=ans;i++)
		if(~req[i]){
			printf("%lld %lld\n",ans,req[i]);
			return 0;
		}
//	printf("%lld\n",ans);
	l=fill(req)[1],r=n;
	int ans1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(ans,mid))ans1=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld %lld\n",ans,ans1);
}