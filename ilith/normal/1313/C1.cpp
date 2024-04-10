#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long up[500010],down[500010];
long long ans[500010];
long long n,pre,temp=0;
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		pre=a[i];
		for(long long j=i;j>0;j--){
			pre=min(a[j],pre);
			up[i]+=pre;
		}
	}
	for(long long i=1;i<=n;i++){
		pre=a[i];
		for(long long j=i;j<=n;++j){
			pre=min(a[j],pre);
			down[i]+=pre;
		}
	}
	for(long long i=1;i<=n;i++){
		if(up[temp]+down[temp]-a[temp]<up[i]+down[i]-a[i]){
			temp=i;
		}
	}
	ans[temp]=a[temp];
	for(long long i=temp-1;i>0;i--){
		ans[i]=min(ans[i+1],a[i]);
	}
	for(long long i=temp+1;i<=n;i++){
		ans[i]=min(ans[i-1],a[i]);
	}
	for(long long i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}