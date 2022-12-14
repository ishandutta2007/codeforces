#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000005;
#define N 100
#define ll long long
#define int long long
int t,n,mx,sum,a[N],i,day;
inline int check(int mid){
	ll x=0;
	int j,ss=sum;
	for(j=i;j<=day;++j){
		a[j]=min(mid,inf);
		ss+=mid;
		ss=min(ss,inf);
		mid=ss;
	}
	for(j=i;j<=day;++j)x+=1ll*a[j]*(day-j+1);
	return x>=n;
}
int l,r,mid;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		mx=2;day=0,sum=1;
		while(mx<=n)mx<<=1,++day;
		cout<<day<<"\n";n-=day+1;
		for(i=1;i<=day;++i){
			l=0,r=sum;
			while(l<r){
				mid=(l+r>>1);
				if(check(mid))r=mid;
				else l=mid+1;
			}
			sum+=l;
			n-=l*(day-i+1);
			cout<<l<<" ";
		}
		cout<<"\n";
	}
	return 0;
}