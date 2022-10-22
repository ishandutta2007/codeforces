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
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,t0,t1;
string s;

int main(){
	cin>>t;
	f(q,0,t){
		t0=t1=0;
		cin>>n>>s;
		for(t0=0;t0<s.size() && s[t0]=='0';t0++){}
		for(int i=s.size()-1;i>=0 && s[i]=='1';i--) t1++;
		if(t1+t0==n)
			cout<<s<<endl;
		else{
			f(i,0,t0+1)
				cout<<0;
			f(i,0,t1)
				cout<<1;
			cout<<endl;
		}
	}
}