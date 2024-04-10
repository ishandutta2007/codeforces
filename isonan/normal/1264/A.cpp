#include <cstdio> 

int t,n,cnt[400001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		int top=0;
		for(int i=1,last=-1,tem;i<=n;i++){
			scanf("%d",&tem);
			if(tem==last)++cnt[top];
			else cnt[++top]=1;
			last=tem;
		}
		for(int i=1;i<=top;i++)cnt[i]+=cnt[i-1];
		int p=0,g=0,s=0,b=0;
		for(int i=1;i<=top;i++)
			if(cnt[i]<=(n>>1))p=i;
		for(int i=1;i<=p;i++){
			int l=i+1,r=p,mid,ans=-1;
			while(l<=r){
				mid=(l+r)>>1;
				if(cnt[mid]-cnt[i]>cnt[i])ans=mid,r=mid-1;
				else l=mid+1;
			}
			if(ans!=-1&&cnt[p]-cnt[ans]>cnt[i]){
				g=cnt[i],s=cnt[ans]-cnt[i],b=cnt[p]-cnt[ans];
				break;
			}
		}
		printf("%d %d %d\n",g,s,b);
	}
}