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
const int N=501;
int t,xa,ya,xb,yb,xc,yc,mn=1e9,x,y,n=1002;
vector<pair<int,int> > ans;
void solve(int a,int b,int c,int d){
	while(b>d){
		ans.pb(mp(a,b--));
	}
	while(b<d)
		ans.pb(mp(a,b++));
	while(a<c)
		ans.pb(mp(a++,b));
	while(a>c)
		ans.pb(mp(a--,b));
}
int dist(int y1,int y2,int y3,int y4){
	return abs(y1-y3)+abs(y2-y4);
}
int main(){
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	f(i,0,n){
		f(j,0,n){
			if(dist(xa,ya,i,j)+dist(xb,yb,i,j)+dist(xc,yc,i,j)+1<mn){
				mn=dist(xa,ya,i,j)+dist(xb,yb,i,j)+dist(xc,yc,i,j)+1;
				x=i,y=j;
			}
		}
	}
	cout<<mn<<endl;
	ans.pb(mp(x,y));
	solve(xa,ya,x,y),solve(xb,yb,x,y),solve(xc,yc,x,y);
	f(i,0,mn){
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
	}
}