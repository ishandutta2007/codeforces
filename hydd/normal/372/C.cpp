#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,d,a,b,t[2];
int head,tail,que[160000];
ll k,f[2][160000],sum,ans;
inline int myabs(int x){
	if (x<0) x=-x;
	return x;
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&t[i&1]);
		k=1ll*(t[i&1]-t[(i&1)^1])*d;
        head=1,tail=0;
        for (int j=1;j<=n;j++){
            while (head<=tail&&que[head]<j-k) head++;
            while (head<=tail&&f[(i&1)^1][que[tail]]>f[(i&1)^1][j]) tail--;
            que[++tail]=j;
            f[i&1][j]=f[(i&1)^1][que[head]]+myabs(a-j);
        }
        head=1,tail=0;
        for (int j=n;j>=1;j--){
        	while (head<=tail&&que[head]>j+k) head++;
        	while (head<=tail&&f[(i&1)^1][que[tail]]>f[(i&1)^1][j]) tail--;
        	que[++tail]=j;
            f[i&1][j]=min(f[i&1][j],f[(i&1)^1][que[head]]+myabs(a-j));
		}
		sum+=b;
	}
	ans=1e18;
	for (int i=1;i<=n;i++) ans=min(ans,f[m&1][i]);
	printf("%lld\n",sum-ans);
	return 0;
}