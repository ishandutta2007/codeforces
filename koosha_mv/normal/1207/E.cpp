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
const int N=(1<<14);
int n,x,mark[N],t,a[N],b[N];
vector<int> v;
int xrr(int x,int y){
	int res=0;
	f(i,0,14){
		res+=(1<<i)*(x%2!=y%2);
		x/=2;
		y/=2;	
	}
	return res;
}
bool check(int x){
	f(i,0,v.size()){
		if(mark[xrr(x,v[i])])
			return 0;
	}
	return 1;
}
int main(){
	cout<<"?";
	f(i,0,100) cout<<" "<<i;
	cout<<endl;
	fflush(stdout);
	cin>>x;
	f(i,0,100){
		if(!mark[xrr(i,x)]){
			mark[xrr(i,x)]=1;
			v.pb(xrr(i,x));
		}
	}
	fill(mark,mark+N,0);
	f(i,100,N){
		if(t==100) break;
		if(check(i)){
			f(j,0,v.size())
				mark[xrr(i,v[j])]=1;
			a[t++]=i;
		}
	}
	f(i,0,v.size()) b[v[i]]=1;
	cout<<"?";
	f(i,0,100) cout<<" "<<a[i];
	cout<<endl;
	fflush(stdout);
	cin>>x;
	f(i,0,100){
		if(b[xrr(a[i],x)])
			return cout<<"! "<<xrr(a[i],x),0;
	}
	
}