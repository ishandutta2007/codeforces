#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int a[N<<1],a1[N],a2[N];
int main(){
	int i,n,q;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	a1[0]=a[1];a2[0]=a[2];
	int mx=a[1],id=1,he=1,ta=n;ll t;
	for(i=2;i<=n;++i)if(a[i]>mx){mx=a[i];id=i;}
	for(i=1;i<id;++i){
		if(a[he]<=a[he+1])a[++ta]=a[he++];
		else{a[++ta]=a[++he];a[he]=a[he-1];}
		a1[i]=a[he];a2[i]=a[he+1];
	}
//	for(i=he;i<=ta;++i)printf("%d ",a[i]);printf("QUE\n");
	for(;q;--q){
		scanf("%I64d",&t);--t;
		if(t<id)printf("%d %d\n",a1[t],a2[t]);
		else printf("%d %d\n",mx,a[(he+1)+(t-id+1)%(n-1)]);//printf("id=%d\n",(t-id+1)%(n-1));
	}
	return 0;
}