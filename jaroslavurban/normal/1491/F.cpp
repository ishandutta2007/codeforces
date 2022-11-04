#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>res(n);
		int idx=0,sum=0;
		for(;idx<n;++idx){
			cout<<"? 1 "<<n-idx-1<<endl;
			cout<<idx+1<<endl;
			for(int i=idx+1;i<n;++i)cout<<i+1<<" ";cout<<endl;
			cin>>sum;
			if(sum)break;
		}
		res[idx]=true;
		for(int i=idx+1;i<n-1;++i){
			cout<<"? 1 1"<<endl;
			cout<<idx+1<<endl;
			cout<<i+1<<endl;
			cin>>res[i];
			sum-=res[i];
		}
		res[n-1]=sum;
		int l=0,r=idx;
		while(l<r){
			int m=(l+r)/2;
			cout<<"? "<<m+1<<" "<<1<<endl;
			for(int i=0;i<=m;++i)cout<<i+1<<" ";cout<<endl;
			cout<<idx+1<<endl;
			int f;cin>>f;
			if(f)r=m;
			else l=m+1;
		}
		res[l]=1;
		cout<<"! "<<count(res.begin(),res.end(),0)<<" ";
		for(int i=0;i<n;++i)if(!res[i])cout<<i+1<<" ";cout<<endl;
	}
}