// Hydro submission #6197084fd28d95852ab352d6@1637288016081
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],q[N],head,tail;
long long f[N];
double F(int x,int y){return 1.0*(f[y]-f[x])/(b[x]-b[y]);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	f[1]=b[1];
	head=tail=1;
	q[1]=1;
	for(int i=2;i<=n;i++){
		while(head<tail&&F(q[head],q[head+1])<a[i]-1)head++;
		f[i]=f[q[head]]+1ll*(a[i]-1)*b[q[head]]+b[i];
		while(head<tail&&F(q[tail-1],q[tail])>F(q[tail],i))tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
}