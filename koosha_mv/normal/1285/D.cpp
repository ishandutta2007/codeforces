#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1e5+9;
ll n,a[N][33],ans[33],tvn[33],x;
vector<int> l;
ll dp(int j,vector<int> v){
	vector<int> v0,v1;
	ll p,p2;
	if(j==33) return 0;
	f(i,0,v.size()){
		if(a[v[i]][j]==1)
			v1.pb(v[i]);
		else
			v0.pb(v[i]);
	}
	if(v0.size()==0){
		p=(dp(j+1,v1));
		return p;
	}
	if(v1.size()==0){
		p=dp(j+1,v0);
		return p;
	}
	p=dp(j+1,v0);
	p2=dp(j+1,v1);
	if(p<p2){
		p+=tvn[j];
		return p;
	}
	else{
		p2+=tvn[j];
		return p2;
	}
	
}
int main(){
	tvn[32]=1;
	f_(i,31,0) tvn[i]=tvn[i+1]*2;
	cin>>n;
	f(i,0,n){
		cin>>x;
		f_(j,32,0){
			a[i][j]=x%2;
			x/=2;
		}
	}
	f(i,0,n)
		l.pb(i);
	ll w=dp(0,l);
	cout<<w;
}