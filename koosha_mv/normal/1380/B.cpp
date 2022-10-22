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
#define ops(x) cout<<x<<" !"<<endl
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

const int N=5e5+99;

int n,t,d[3];
string s,g="RPS";

int main(){
	cin>>t;
	while(t--){
		d[0]=d[1]=d[2]=0;
		char ans;
		cin>>s;
		f(i,0,s.size())
			f(j,0,3)
				if(s[i]==g[j])
					d[j]++;
		if(d[0]>=d[1] && d[0]>=d[2]) ans=g[1];
		else{
			if(d[1]>=d[0] && d[1]>=d[2]) ans=g[2];
			else ans=g[0];
		}
		f(i,0,s.size()) cout<<ans;
		cout<<endl;
	}
}