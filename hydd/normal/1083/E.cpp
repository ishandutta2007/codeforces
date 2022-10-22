#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,que[1100000];
ll ans,f[1100000];
struct node{
	int x,y;
	ll c;
	bool operator<(const node &a) const{ return x<a.x;}
} a[1100000];
long double slope(int x,int y){ return (long double)(f[y]-f[x])/(a[y].x-a[x].x);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].c);
	sort(a+1,a+n+1);
	int head=1,tail=1; que[1]=0;
	for (int i=1;i<=n;i++){
		while (head<tail&&slope(que[head],que[head+1])>=a[i].y) head++;
		f[i]=max(1ll*a[i].x*a[i].y,f[que[head]]+1ll*(a[i].x-a[que[head]].x)*a[i].y)-a[i].c;
		ans=max(ans,f[i]);
		while (head<tail&&slope(que[tail-1],que[tail])<=slope(que[tail],i)) tail--;
		que[++tail]=i;
	}
	printf("%lld\n",ans);
	return 0;
}