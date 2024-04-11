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
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2003;

int n,t,p,x,a[N],mark[N*4];
vector<int> ans;

void solve(int x){
	f(i,0,n)
		a[i]+=mark[x+i];
	f(i,0,n)
		if(a[i]<i || (a[i]-i)%p==0)
			return;
	ans.pb(x);
}

int main(){
	cin>>n>>p;
	f(i,0,n){
		gett(x);
		mark[x]++;
		f(j,x,N) a[j]++;
	}
	f(i,1,N)
		solve(i);	
	cout<<ans.size()<<endl;
	print(ans,ans.size());
}