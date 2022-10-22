#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
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

const int N=102;

int n,t,ans,a[N],mark[N];

int calc(int x){
	int res=0;
	f(i,1,x/2+1){
		if(x%2==0 && i==x/2) res+=mark[i]/2;
		else res+=min(mark[i],mark[x-i]);
	}
	return res;
}

int main(){
	cin>>t;
	while(t--){
		fill(mark,mark+N,0);
		ans=0;
		cin>>n;
		f(i,0,n){ cin>>a[i]; mark[a[i]]++; }
		f(i,2,n*2+1)
			maxm(ans,calc(i));
		cout<<ans<<endl;
	}
}