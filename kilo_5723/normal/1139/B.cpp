#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const ll inf=1e18;
ll a[maxn];
ll que[maxn],ord[maxn],siz;
ll cal(ll a,ll h){
	if (h>a) h=a;
	return (a+a-h+1)*h/2;
}
int main(){
	int i,n;
	ll t,ans,cur;
	scanf("%d",&n);
	siz=1; ans=0; cur=0;
	que[0]=-inf; ord[0]=-1;
	for (i=0;i<n;i++){
		scanf("%I64d",&t);
		while (que[siz-1]-ord[siz-1]>=t-i){
			cur-=cal(que[siz-1],ord[siz-1]-ord[siz-2]);
			siz--;
		}
		cur+=cal(t,i-ord[siz-1]);
		que[siz]=t; ord[siz]=i; siz++;
		ans=max(ans,cur);
	}
	printf("%I64d\n",cur);
	return 0;
}