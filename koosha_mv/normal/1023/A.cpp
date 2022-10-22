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

const int N=5e5+99;

int n,m,p=-1,e;
string s,t;

int main(){
	cin>>n>>m;
	cin>>s>>t;
	f(i,0,n)
		if(s[i]=='*')
			p=i;
	if(p==-1)
		return cout<<(s==t ? "YES" : "NO"),0;
	if(n>m+1) return cout<<"NO",0; 
	f(i,0,p)
		if(s[i]!=t[i])
			return cout<<"NO",0;
	e=m;
	f_(i,n-1,p+1){
		e--;
		if(s[i]!=t[e])
			return cout<<"NO",0;
	}
	cout<<"YES";
}