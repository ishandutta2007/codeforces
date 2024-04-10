#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,id;
}a[200010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int i,j,k,n,m,Ans[200010];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)scanf("%d",&a[i].w),a[i].id=i;
		sort(a+1,a+1+n,cmp);
		long long ans=0;
		for(i=n;i>=1;i--)
			ans+=1ll*(n-i+2)/2*a[i].w;
		cout<<ans*2<<endl;
		printf("0");
		for(i=n;i>=1;i--)
			Ans[a[i].id]=(i&1?1:-1)*(n-i+2)/2;
		for(i=1;i<=n;i++)
			printf(" %d",Ans[i]);
		puts("");
	}
	return 0;
}