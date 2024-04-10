#include <bits/stdc++.h>
using namespace std; 
long long tuning[100005],diff[100005],sum[100005];
int bsearch(long long n,long long s,long long e){
	if(s==e)return s;
	long long mid=(s+e)/2;
	if(n<diff[mid])return bsearch(n,s,mid);
	if(n==diff[mid])return mid;
	return bsearch(n,mid+1,e);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>tuning[i];
	sort(tuning,tuning+n);
	for(int i=0;i<n-1;i++)diff[i]=tuning[i+1]-tuning[i];
	diff[n-1]=pow(10,18)*5;
	sort(diff,diff+n);
	sum[0]=diff[0];
	for(int i=1;i<n;i++)sum[i]=sum[i-1]+diff[i];
	long long m,a,b,d,ans;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		d=b-a+1;
		long long p=bsearch(d,0,n-1);
		while(diff[p]>=d&&p!=-1){
			p--;	
		}
		//cout<<p<<" ";
		if(p==-1)ans=d*n;
		else{
			ans=0;
			ans+=sum[p];
			ans+=(n-p-1)*d;
		}
		cout<<ans;
		if(i!=m-1)cout<<" ";
		//cout<<endl;
	}
	cout<<endl;
	return 0;
}