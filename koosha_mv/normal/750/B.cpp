#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

int n,h=20000,t[N];
string s[N];

int main(){
	cin>>n;
	f(i,0,n){
		cin>>t[i]>>s[i];
		if(h==20000 && (s[i][0]!='S')) return cout<<"NO",0;
		if(h==0 && s[i][0]!='N') return cout<<"NO",0;
		if(s[i][0]=='N'){
			h+=t[i];
			if(h>20000) return cout<<"NO",0;
		}
		if(s[i][0]=='S'){
			h-=t[i];
		//	ops(h);
			if(h<0) return cout<<"NO",0;
		}
	}
	if(h!=20000) return cout<<"NO",0;
	cout<<"YES";
}