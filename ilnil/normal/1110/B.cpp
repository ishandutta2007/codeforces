#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,m,k,ans;
int b[N],a[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,n)scanf("%d",&b[i]);
	ans=b[n]-b[1];
	fo(i,1,n-1)a[i]=b[i+1]-b[i];
	sort(a+1,a+n);
	fd(i,n-k+1,n-1)
		ans-=a[i];
	ans+=k;
	printf("%d\n",ans);
}