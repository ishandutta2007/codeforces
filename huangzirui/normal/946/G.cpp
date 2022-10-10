#include<stdio.h>
#include<algorithm>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=200005;
int n,tot,ans;
int a[maxn],b[maxn],t[maxn<<1][3],f[maxn][2],num[maxn<<1];
void update(int x,int v,int tp){
	for(int i=x;i<=tot;i+=lowbit(i))
		t[i][tp]=max(t[i][tp],v);
}
int query(int x,int tp){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res=max(res,t[i][tp]);
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]-=i,b[i]=a[i]+1,num[i]=a[i],num[n+i]=b[i];
		sort(num+1,num+1+n*2),tot=unique(num+1,num+1+n*2)-num-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(num+1,num+1+tot,a[i])-num,b[i]=lower_bound(num+1,num+1+tot,b[i])-num;
	for(int i=1;i<=n;i++){
		f[i][0]=query(a[i],0)+1;
		if(query(a[i],1)>0)
			f[i][1]=query(a[i],1)+1;
		else f[i][1]=0;
		if(i>2)
			f[i][1]=max(f[i][1],query(b[i],2)+1);
		update(a[i],f[i][0],0),update(a[i],f[i][1],1);
		if(i>1)
			update(a[i-1],f[i-1][0],2);
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%d\n",max(n-ans-1,0));
	return 0;
}