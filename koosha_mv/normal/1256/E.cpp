#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define koosha_Mv main
const int N=2e5+9;
ll dp[N],n,p1,p2,cnt=1,kh[N],ans[N];
pair<ll,ll> a[N];
int koosha_Mv(){
	cin>>n;
	f(i,1,n+1){scanf("%I64d",&a[i].first);dp[i]=1e12;a[i].second=i;}
	sort(a+1,a+n+1);
	f(i,3,n+1){
		f(j,max(i-8,(ll)0),i-2){
			dp[i]=min(dp[i],dp[j]+a[i].first-a[j+1].first);
		}
	}
	p2=n;
	p1=n-3;
	while(p2>0){
		if(dp[p1]+a[p2].first-a[p1+1].first==dp[p2]){
			kh[p2]=cnt;
			cnt++;
			p2=p1;
			p1-=3;
		}
		else p1--;
	}
	f_(i,n+1,1){
		if(kh[i]==0) kh[i]=kh[i+1];
		ans[a[i].second]=kh[i];
	}
	cout<<dp[n]<<" "<<cnt-1<<endl;
	f(i,1,n+1) cout<<ans[i]<<" ";
}