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
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,p,m,ans,res,a[N],b[N],mn[N],mx[N];
vector<int> v[N];
map<int,int> tanz;

int calc(int an,int x,int s){
	int l=-1,r=v[an].size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(v[an][mid]<x) l=mid;
		else r=mid;
	}
	if(s==0) return l+1;
	return v[an].size()-r;
}
void mv(int x){
	p=0;
	f(i,0,v[x].size()){
		while(p<v[x+1].size() && v[x][i]>v[x+1][p])
			p++;
		maxm(res,int(i+1+v[x+1].size()-p));
	}
}
void make_a(){
	fill(mn,mn+n+2,N);
	fill(mx,mx+n+2,0);
	p=0;
	f(i,0,n+2) v[i].clear();
	f(i,1,n+1){ gett(a[i]); b[i]=a[i];}
	sort(b+1,b+1+n);
	f(i,1,n+1)
		if(i==1 || b[i]!=b[i-1])
			tanz[b[i]]=++p;
	f(i,1,n+1){ a[i]=tanz[a[i]]; v[a[i]].pb(i); minm(mn[a[i]],i); maxm(mx[a[i]],i); }
	m=p;
}
void solve(){
	int i=1;
	res=0;
	cin>>n;
	make_a();
	for(;i<=m;){
		p=i+1,ans=v[i].size();
		while(mn[p]>mx[p-1] && p<=m)
			ans+=v[p].size(),p++;
		ans+=calc(i-1,mn[i],0);
		ans+=calc(p,mx[p-1],1);
		maxm(res,ans);
		i=p;
	}
	f(i,1,m)
		mv(i);
	cout<<n-res<<endl;
}

int main(){
	cin>>t;
	f(q,0,t)
		solve();
}