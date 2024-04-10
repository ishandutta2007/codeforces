#include <cstdio>
#include <algorithm>

int t,n,a[50001],x;
long long S[50001];
int stk[50001],top,f[50001],P[50001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		scanf("%d",&x);
		for(int i=1;i<=n;++i)a[i]-=x;
		top=0;
		stk[++top]=0;
		P[1]=-1;
		for(int i=1;i<=n;++i)S[i]=S[i-1]+a[i];
		for(int i=1,p=1;i<=n;++i){
			f[i]=f[i-1];
			
			if(i<n){
				int l=1,r=top,ans=0,mid;
				while(l<=r){
					mid=(l+r)>>1;
					if(S[stk[mid]]>S[i+1])l=mid+1,ans=mid;
					else r=mid-1;
				}
				// printf("%d %d\n",i+1,ans);
				if(ans)P[i+1]=stk[ans];
				else P[i+1]=-1;
			}
			while(top&&S[stk[top]]<S[i])--top;
			stk[++top]=i;
			if(P[i]!=-1)p=std::max(p,P[i]+2);
			f[i]=std::max(f[i],((p>=2)?f[p-2]:0)+i-p+1);
			// printf("%d %d %d %d\n",S[i],f[i],p,P[i+1]);
			// for(int i=1;i<=top;++i)printf("%d ",S[stk[i]]);putchar('\n');
		}
		printf("%d\n",f[n]);
	}
}