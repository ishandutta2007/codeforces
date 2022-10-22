#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99,inf=1e10;

int n,t,a[N];

void Main(){
	map<pair<int,int> ,int> mark;
	cin>>n;
	int mn=inf,mx=0,cost1=inf,cost2=inf,cost3=inf;
	f(i,0,n){
		int l,r,c;
		cin>>l>>r>>c;
		if(l<mn){
			mn=l;
			cost1=c;
			cost3=inf;
		}
		if(l==mn){
			minm(cost1,c);
		}
		if(r>mx){
			mx=r;
			cost2=c;
			cost3=inf;
		}
		if(r==mx){
			minm(cost2,c);
		}
		if(l==mn && r==mx){
			minm(cost3,c);
		}
		int res=cost1+cost2;
		cout<<min(res,cost3)<<endl;
	}
}

main(){
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
5
5 5 10
5 5 1
5 5 2
*/