#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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

const ll N=505,inf=1e9+1;

ll t,n,a[N],b[N];
map<ll,int> m;

ll make(ll x,ll y){
	if(x>y) swap(x,y);
	return x*inf+y;
}
string solve(){
	if(n%2 && a[n/2]!=b[n/2]) return "No";
	f(i,0,n/2)
		m[make(a[i],a[n-1-i])]++;
	f(i,0,n/2)
		if(--m[make(b[i],b[n-1-i])]<0) return "No";
	return "Yes";
}

int main(){
	cin>>t;
	while(t--){
		m.clear();
		cin>>n;
		f(i,0,n) cin>>a[i];
		f(i,0,n) cin>>b[i];
		cout<<solve()<<endl;
	}
}