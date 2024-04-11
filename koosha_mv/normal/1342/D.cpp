#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,k,a[N],c[N],l,r,mid,x;
vector<int> v[N],ans[N];
pair<int,int> b[N];

ll saghf(ll x,ll y){
	return (x/y)+(x%y>0);
}
bool check(int x){
	ll sum=0;
	f_(i,k,1){
		sum+=v[i].size();
		if(saghf(sum,x)>c[i]){ return 0; }
	}
	return 1;
}

int main(){
	cin>>n>>k;
	f(i,0,n){
		gett(x);
		b[i]=mp(x,i+1);
		v[x].pb(i+1);
	}
	f(i,0,k) gett(c[i+1]);
	l=0,r=n+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	sort(b,b+n);
	f(i,0,n){
		ans[i%r].pb(b[n-i-1].F);
	}
	f(i,0,r){
		cout<<ans[i].size()<<" ";
		f(j,0,ans[i].size()) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}