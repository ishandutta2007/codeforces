/*
	Time: 2020/12/20 21:13 - 21:22
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,a[11000],sum;
int ans,Ansx[31000],Ansy[31000],Ansz[31000];
void mymove(int x,int y,int z){
	if (!z) return;
	assert(a[x]>=z&&z%x==0);
	a[x]-=z; a[y]+=z;
	ans++; Ansx[ans]=x; Ansy[ans]=y; Ansz[ans]=z/x;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); sum=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if (sum%n){
			puts("-1");
			continue;
		}
		sum/=n; ans=0;
		for (int i=2;i<=n;i++){
			mymove(1,i,(i-a[i]%i)%i);
			mymove(i,1,a[i]);
		}
		for (int i=2;i<=n;i++) mymove(1,i,sum);
		for (int i=1;i<=n;i++) assert(a[i]==sum);
		printf("%d\n",ans);
		for (int i=1;i<=ans;i++) printf("%d %d %d\n",Ansx[i],Ansy[i],Ansz[i]);
	}
	return 0;
}