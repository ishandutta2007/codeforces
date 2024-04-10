#include<cstdio>
#include<algorithm>
using namespace std;
int n,f[110000],Ans[110000],path[110][2100];
struct node{
	int t,d,p,id;
	bool operator<(const node &a) const{ return d<a.d;}
} a[110000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		for (int j=a[i].d-1;j>=a[i].t;j--)
			if (f[j]<f[j-a[i].t]+a[i].p){
				f[j]=f[j-a[i].t]+a[i].p;
				path[i][j]=true;
			}
	int ans=1,cnt=0;
	for (int i=2;i<a[n].d;i++)
		if (f[i]>f[ans]) ans=i;
	printf("%d\n",f[ans]);
	for (int i=n;i>=1;i--)
		if (path[i][ans]){
			Ans[++cnt]=a[i].id;
			ans-=a[i].t;
		}
	printf("%d\n",cnt);
	for (int i=cnt;i>1;i--) printf("%d ",Ans[i]);
	if (cnt) printf("%d\n",Ans[1]);
	return 0;
}