#include <cstdio>

int n;
int get(int x){
	if(x>n)return 0x7f7f7f7f;
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(get(mid)<get(mid+1))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("! %d\n",ans);
}