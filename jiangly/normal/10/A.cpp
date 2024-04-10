#include<bits/stdc++.h>
const int MAXN=100;
int n,p1,p2,p3,t1,t2;
int l[MAXN+5],r[MAXN+5];
int ans;
int main(){
	scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=n;++i)
		ans+=(r[i]-l[i])*p1;
	for(int i=1;i<n;++i){
		int t=l[i+1]-r[i];
		if(t<=t1)
			ans+=t*p1;
		else if(t<=t1+t2)
			ans+=t1*p1+(t-t1)*p2;
		else
			ans+=t1*p1+t2*p2+(t-t1-t2)*p3;
	}
	printf("%d\n",ans);
	return 0;
}