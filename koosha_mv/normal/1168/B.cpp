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

int n,t,ans;
string s,e;

bool check(int l,int r){
	f(x,l,r)
		f(k,1,(r-l+1))
			if(x+k+k<=r && s[x]==s[x+k] && s[x]==s[x+k+k])
				return 0;
	//cout<<l<<" "<<r<<endl;
	return 1;
}

int main(){
	cin>>s;
	n=s.size();
	f(i,0,n)
		f(j,0,min(n-i,10))
			if(check(i,i+j))
				ans++;
	cout<<1ll*n*(n+1ll)/2-ans;
}