#include <cstdio>
#include <cstring>
#define int long long

int n,a[200001],c[200001],p[200001];
long long d[200001];
long long ans[200001];
void update(int ind,int num){
	for(;ind<=n;ind+=ind&-ind)d[ind]+=num;
}
long long queryd(int ind){
	long long tot=0;
	for(;ind;ind-=ind&-ind)tot+=d[ind];
	return tot;
}
void update(int ind){
	for(;ind<=n;ind+=ind&-ind)c[ind]++;
}
int query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),p[a[i]]=i;
	for(int i=n;i;i--){
		ans[a[i]]=query(a[i]);
		update(a[i]);
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
	memset(c,0,sizeof c);
	long long sum=0;
	for(int i=1;i<=n;i++){
		update(p[i]);
		update(p[i],p[i]);
		sum+=p[i];
		int l=1,r=n,mid,ans=-1,pos=(i+1)>>1;
		while(l<=r){
			mid=(l+r)>>1;
			if(query(mid)>=pos)ans=mid,r=mid-1;
			else l=mid+1;
		}
		long long tem=queryd(ans-1)+(pos-query(ans-1)-1)*ans;
		printf("%lld ",(::ans[i])-((1ll*(pos-1)*(pos))>>1ll)+ans*(pos-1)-tem-ans*(i-pos)-((1ll*(i-pos)*(i-pos+1))>>1ll)+(sum-tem-ans));
	}
}