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
const int N=105,midle=(1<<15);

int n,a[N],b[N],x;
map<vector<int>,int> mark;

int xrr(int x,int y){
	int ans=0;
	while(x || y){
		if(x%2!=y%2)
			ans++;
		x/=2,y/=2;
	}
	return ans;
}
void solve(int x){
	int source=xrr(a[0],x);
	vector<int> v;
	f(i,1,n)
		v.pb(xrr(a[i],x)-source);
	mark[v]=x+1;
}
void hello(int x){
	int source=xrr(b[0],x);
	vector<int> v;
	f(i,1,n)
		v.pb(source-xrr(b[i],x));
	if(mark[v]>0){
		cout<<x+midle*(mark[v]-1);
		exit(0);
	}
}
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x;
		a[i]=x/midle;
		b[i]=x%midle;
	}
	f(i,0,midle)
		solve(i);
	f(i,0,midle)
		hello(i);
	cout<<-1;
}