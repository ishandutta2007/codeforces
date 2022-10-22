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

int n,t,ans,cnt[10];
string s;

int calc(int x,int y){
	int res=n;
	bool b=1;
	f(i,0,n){
		if(b && s[i]-'0'==x)
			res--,b=1-b;
		if(!b && s[i]-'0'==y)
			res--,b=1-b;
	}
	if(!b) res++;
	return res;
}

int main(){
	cin>>t;
	while(t--){
		fill(cnt,cnt+10,0);
		cin>>s;
		n=s.size();
		ans=n;
		f(i,0,n)
			cnt[s[i]-'0']++;
		f(i,0,10)
			minm(ans,n-cnt[i]);
		f(i,0,10)
			f(j,0,10)
				if(i!=j)
					minm(ans,calc(i,j));
		cout<<ans<<'\n';
	}
}