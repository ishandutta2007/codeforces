#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,A,R,M,a[100010],l=INT_MAX,r=0,ans=0;
long long chk(int x){
	long long d=0,u=0,ct=0;
	for(int i=1;i<=n;i++) a[i]>=x?u+=a[i]-x:d+=x-a[i];
	if(d>u) ct+=(d-u)*A;
	if(u>d) ct+=(u-d)*R;
	ct+=min(d,u)*min(A+R,M);
	return ct;
}
int main(){
	scanf("%d %d %d %d",&n,&A,&R,&M);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),l=min(a[i],l),r=max(a[i],r);
	while(l<=r){
		int lmid=(r-l)/3+l,rmid=r-(r-l)/3;
		if(chk(lmid)<=chk(rmid)) ans=lmid,r=rmid-1;
		else l=lmid+1,ans=rmid;
	}
	printf("%lld\n",chk(ans));
}