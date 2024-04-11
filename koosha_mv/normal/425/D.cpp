#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9;

int n,x,y,ans,mv,markx[N];
map<pair<int,int>,bool> mark;
pair<int,int> point[N];
vector<int> bx[N],by[N],bxy[N*2];

bool check_is(pair<int,int> p){
	int l=0,r=mv,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(point[mid]<=p) l=mid;
		else r=mid;
	}
	return (point[l]==p);
}
bool calc(int x,int y,int an){
	int t=max(x-point[an].F,y-point[an].S);
	return (check_is(mp(x-t,y)) && check_is(mp(x,y-t)) && check_is(mp(x-t,y-t)));
}
void solve(int x,int y,int an){
	int xy=x-y+N;
	mv=an;
	int mn=min(bxy[xy].size(),min(bx[x].size(),by[y].size()));
	if(mn==bx[x].size()){
		f(i,0,bx[x].size())
			ans+=calc(x,y,bx[x][i]);
	}
	else if(mn==by[y].size()){
		f(i,0,by[y].size())
			ans+=calc(x,y,by[y][i]);
	}
	else{
		f(i,0,bxy[xy].size())
			ans+=calc(x,y,bxy[xy][i]);
	}
	bx[x].pb(an);
	by[y].pb(an);
	bxy[xy].pb(an);
}

int main(){
	cin>>n;
	f(i,0,n){
		Gett(x,y);
		mark[mp(x,y)]=1;
		point[i]=mp(x,y);
	}
	sort(point,point+n);
	f(i,0,n)
		solve(point[i].F,point[i].S,i);
	cout<<ans<<'\n';
}