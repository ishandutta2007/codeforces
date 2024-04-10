#include<bits/stdc++.h>
using namespace std; 
long long t;
struct node{
	long long mx,sm;
}a[200010];
bool operator<(node a,node b){
	return a.mx<b.mx;
}
int main(){
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long sum=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i].mx;
		}
		for(long long i=1;i<=n;i++){
			cin>>a[i].sm;
			sum+=a[i].sm;
		}
		sort(a+1,a+n+1);
		long long ans=sum;
		for(long long i=1;i<=n;i++){
			sum-=a[i].sm;
			ans=min(ans,max(sum,a[i].mx));
		}
		cout<<ans<<'\n';
	}
	return 0;
}