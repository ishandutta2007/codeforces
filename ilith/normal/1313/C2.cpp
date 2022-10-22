#include<bits/stdc++.h>
using namespace std;
stack<long long>q;
long long a[500005];
long long up[500005],down[500005];
long long ans[500005];
int main(){
	long long n,pre,ansn=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		while(!q.empty()&&a[q.top()]>a[i]){
			q.pop();
		}
		pre=0;
		if(!q.empty()){
			pre=q.top();
		}
		q.push(i);
		up[i]=up[pre]+(i-pre)*a[i];
	}
	while(!q.empty()){
		q.pop();
	}
	for(long long i=n;i>0;i--){
		while(!q.empty()&&a[q.top()]>a[i]){
			q.pop();
		}
		pre=q.empty()?n+1:q.top();
		q.push(i);
		down[i]=down[pre]+(pre-i)*a[i];
	}
	for(long long i=1;i<=n;i++){
		if(up[ansn]+down[ansn]-a[ansn]<up[i]+down[i]-a[i]){
			ansn=i;
		}
	}
	ans[ansn]=a[ansn];
	for(long long i=ansn-1;i>0;i--){
		ans[i]=min(ans[i+1],a[i]);
	}
	for(long long i=ansn+1;i<=n;i++){
		ans[i]=min(ans[i-1],a[i]);
	}
	for(long long i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}