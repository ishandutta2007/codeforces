#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,k,x,y,a[N],b[N],c[N];
vector<ll> v1,v2,v3;
ll ans=1e18;

ll calc(int x){
	if(k-x>=v1.size() || k-x>=v2.size()) return ans;
	return v3[x]+v1[k-x]+v2[k-x];
}
int main(){
	cin>>n>>k;
	v1.pb(0),v2.pb(0),v3.pb(0);
	f(i,0,n){
		gett(a[i]);
		Gett(x,y);
		if(x==1 && y==1)
			v3.pb(a[i]);
		if(x==1 && y==0)
			v1.pb(a[i]);
		if(x==0 && y==1)
			v2.pb(a[i]);			
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	f(i,1,v1.size()) v1[i]+=v1[i-1];
	f(i,1,v2.size()) v2[i]+=v2[i-1];
	f(i,1,v3.size()) v3[i]+=v3[i-1];
	f(i,0,v3.size())
		minm(ans,calc(i));
	cout<<(ans==1e18 ? -1 : ans);
}