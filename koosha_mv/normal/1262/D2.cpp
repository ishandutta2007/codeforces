#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+99;
int n,m,a[N],ans[N],x,y,l,r,k=18,ct,tvn=131072,e=2e5+100,mid,p1,anss=0,tedad[N*3];
string s;
vector<pair<int,int> > g[N];
pair<int,int> p[N];
string binary(int m,int k){
	string g="";
	f(i,0,k){
		g+=char((m%2)+'0');
		m=m/2;
	}
	return g;}
bool check(int md,int x){
	anss=0;
	s=binary(tvn*2-(n+1-md),k),ct=tvn,p1=tvn*2;
	f_(i,k-1,0){
		if(s[i]=='1'){
			p1-=ct;
			anss+=tedad[p1];
		}
		ct/=2;
	}
	return md-anss<x;
}
int solve(int x){
	l=0;r=n;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid,x)) l=mid;
		else r=mid;
	}
	return a[r];
}
int main(){
	cin>>n;
	f(i,1,n+1){gett(a[i]);p[i-1].F=a[i];p[i-1].S=i;}
	cin>>m;
	f(i,0,m){
		Gett(x,y);
		g[x].pb(make_pair(y,i));
	}
	sort(p,p+n);
	f(i,0,n){
		swap(p[i].F,p[i].S);
		p[i].F=e-p[i].F;
	}
	while(l<n){
		while(p[l].S==p[l+r].S)
			r++;
		sort(p+l,p+l+r);
		l=l+r,r=0;
	}
	f(i,0,n) p[i].F=e-p[i].F;
	f(i,0,n){
		f(j,0,g[n-i].size()){
			ans[g[n-i][j].S]=solve(g[n-i][j].F);
		}
		s=binary(n+1-p[i].F,k),p1=0,ct=tvn;
		f_(j,k-1,0){
			if(s[j]=='1'){
				p1+=ct,tedad[p1]++;
			}
			ct/=2;
		}
	}
	f(i,0,m) cout<<ans[i]<<" ";
}