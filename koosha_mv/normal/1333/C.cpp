#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e6+99;
ll n,t,a[N],mn=-1;
ll ans;
map<ll,ll> mark;
int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		a[i]+=a[i-1];
		if(a[i]==0){
			maxm(mn,mark[a[i]]);
		}
		else{
			if(mark[a[i]]!=0)
				maxm(mn,mark[a[i]]);
		}
		mark[a[i]]=i;
		ans+=i-mn-1;
		//cout<<mn<<" "<<ans<<endl;
	}
	cout<<ans;
}