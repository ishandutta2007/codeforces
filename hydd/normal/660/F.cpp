#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,x,stk[210000];
ll ans,sum1[210000],sum2[210000];
long double slope(int y,int x){ return ((y*sum1[y]-sum2[y])-(x*sum1[x]-sum2[x]))/(y-x);}
inline ll val(int x,int y){ return sum2[y]-sum2[x]-1ll*(x)*(sum1[y]-sum1[x]);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		sum1[i]=sum1[i-1]+x;
		sum2[i]=sum2[i-1]+1ll*i*x;
	}
	int top=0;
	for (int j=1;j<=n;j++){
		ll k=sum1[j];
		int l=0,r=top,mid;
		while (l<r){
			mid=(l+r)>>1;
			if (slope(stk[mid],stk[mid+1])>k) l=mid+1;
			else r=mid;
		}
		int i=stk[r];
        ans=max(ans,val(i,j));
        while (top>=1&&slope(stk[top-1],stk[top])<slope(stk[top],j)) top--;
        stk[++top]=j;
	}
	printf("%lld\n",ans);
	return 0;
}