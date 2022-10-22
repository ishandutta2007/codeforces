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

const int N=5e5+9;

ll n,t,l,r,ans,mid,p[N];

ll calc(ll x){
	
}
void solve(){
	l=1,r=N;
	while(l+1<r){
		mid=(l+r)/2;
		if(p[mid]<=n) l=mid;
		else r=mid;
	}
	n-=p[l];
	ans++;
}

int main(){
	cin>>t;
	p[1]=2;
	f(i,2,N)
		p[i]=p[i-1]+i*2+i-1;
	f(q,0,t){
		cin>>n;
		ans=0;
		while(n>1)
			solve();
		cout<<ans<<endl;
	}
}