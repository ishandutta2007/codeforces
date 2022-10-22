#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int lim=1e6+1;
int n,x,l[1100000],tree[1100000],mn[1100000],mx[1100000];
ll ans;
bool flag[1100000];
void add(int x){
	for (;x<=lim;x+=x&-x) tree[x]++;
}
int getsum(int x){
	int res=0;
	for (;x;x-=x&-x) res+=tree[x];
	return res;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		mn[i]=INF; mx[i]=-INF;
		flag[i]=false;
		for (int j=1;j<=l[i];j++){
			scanf("%d",&x); x++;
			if (x>mn[i]) flag[i]=true;
			mn[i]=min(mn[i],x);
			mx[i]=max(mx[i],x);
		}
	}
	int tot=0;
	for (int i=1;i<=n;i++)
		if (!flag[i]) add(mn[i]);
		else tot++;
	ans=(ll)tot*n*2-(ll)tot*tot;
	for (int i=1;i<=n;i++)
		if (!flag[i]) ans+=getsum(mx[i]-1);
	printf("%lld\n",ans);
	return 0;
}