#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e6+99;
ll n,x,y,ans[N],sum;
pair<ll,ll> p[N];
int main(){
	cin>>n;
	f(i,0,n){
		Get(x,y);
		p[i*2]=make_pair(x,1);
		p[i*2+1]=make_pair(y+1,-1);
	}
	sort(p,p+n*2);
	sum=0;
	f(i,0,n*2-1){
		sum+=p[i].second;
	//	cout<<sum<<endl;
		ans[sum]+=p[i+1].first-p[i].first;
	}
	f(i,1,n+1)
		cout<<ans[i]<<" ";
}