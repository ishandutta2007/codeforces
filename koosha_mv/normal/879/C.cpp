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
#define add(x,y) x=(x+y)%mod;
#define S second
#define F first

const int N=5e5+99;

int n,t,x,a,b,ans1,ans2,ans3;
char c;
int main(){
	cin>>n;
	a=0,b=1023;
	f(i,0,n){
		cin>>c>>x;
		if(c=='&') a=(a & x),b=(b & x);
		if(c=='|') a=(a | x),b=(b | x);
		if(c=='^'){a=(a ^ x),b=(b ^ x); }
	}
	f(i,0,10){
		if(a%2 && b%2) ans1+=(1<<i),ans3+=(1<<i);
		if(a%2 && b%2==0) ans3+=(1<<i),ans2+=(1<<i);
		if(a%2==0 && b%2) ans3+=(1<<i);
		a/=2,b/=2;
	}
	cout<<3<<endl;
	cout<<"| "<<ans1<<endl;
	cout<<"^ "<<ans2<<endl;
	cout<<"& "<<ans3<<endl;
}