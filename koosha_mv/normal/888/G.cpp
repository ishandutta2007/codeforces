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
const int N=2e5+9;

int n,m,x,l,r,mid,a[N];
ll ans;
vector<int> v1,v2,o;

bool check(ll x,ll s){
	l=-1,r=v2.size();
	while(l+1<r){
		mid=(l+r)/2;
		if(v2[mid]<x) l=mid;
		else r=mid;
	}
	if(r==v2.size()) return 0;
	if(v2[r]<x+(1<<s)) return 1;
	return 0;
}
int Get_ans(ll x,ll sz){
	int p=0,ans=0,e;
	f_(i,sz,0){
		e=(x%(1<<(i+1))>=(1<<i));
		if(check(p+(e<<i),i))
			p+=(e<<i);
		else{
			ans+=(1<<i);
			e=!e;
			p+=(e<<i);
		}
	}
	return ans;
}
int minimum_xor(ll sz){
	if(!v1.size() || !v2.size()) return 0;
	int ans=(1<<30);
	sort(v2.begin(),v2.end());
	f(i,0,v1.size())
		minm(ans,Get_ans(v1[i],sz));
	return ans;
}
void solve(vector<int> v,int sz){
	if(sz==-1) return ;
	if(!v.size() || v.size()==1) return ;
	vector<int> v3;
	v1.clear();v2.clear();
	f(i,0,v.size()){
		if(v[i]%(1<<(sz+1))>=(1<<sz))
			v1.pb(v[i]-(1<<sz));
		else
			v2.pb(v[i]);
	}
	ans+=minimum_xor(sz-1);
	if(v1.size() && v2.size()) ans+=(1<<sz);
	f(i,0,v2.size())
		v3.pb(v2[i]);
	solve(v1,sz-1);
	solve(v3,sz-1);
}
int main(){
	cin>>n;
	f(i,0,n) {gett(x);o.pb(x);}
	solve(o,29);
	cout<<ans;
}