#include <cstdio>
#include <cstring>
#include <algorithm>

int c[1000001],n,a[1000001],orig[1000001];
long long x[1000001],ans;
void update(int ind){for(;ind<=n;ind+=ind&-ind)++c[ind];}
int query(int ind){int tot=0;for(;ind;ind-=ind&-ind)tot+=c[ind];return tot;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),orig[i]=a[i];
	std::sort(orig+1,orig+n+1);
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(orig+1,orig+n+1,a[i])-orig;
	for(int i=n;i;i--){
		x[i]=query(a[i]);
		update(a[i]);
	}
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++){
		ans+=x[i]*query(n-a[i]+1);
		update(n-a[i]+1);
	}
	printf("%I64d",ans);
}