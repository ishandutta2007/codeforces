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

const int N=5e5+9;

ll n,t,x,y,c=1,ans[N];
ll e=2e5+2,p;
set<ll> s;

void ins(ll l,ll r){
	s.insert((r-l)*e+(n-l));
}
void update(int l,int r){
	int mid=(l+r)/2;
	ans[mid]=c++;
	if(mid>l)
		ins(l,mid-1);
	if(mid<r)
		ins(mid+1,r);
}
int main(){
	cin>>t;
	while(t--){
		c=1,s.clear();
		cin>>n;
		s.insert(e*(n-1)+n-1);
		while(s.size()){
			p=*s.rbegin();
			s.erase(p);
			x=p%e,y=p/e;
			x=n-x;
			update(x,x+y);
		}
		f(i,1,n+1) cout<<ans[i]<<" ";
		cout<<endl;
	}
}