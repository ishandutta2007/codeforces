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

const int N=1e6+99;

int n,a,x,k,mark[N];
vector<pair<int,int> > comp;
int main(){
	cin>>n>>k;
	for(int i=2;i*i<=k;i++){
		int cnt=0;
		if(k%i==0){
			while(k%i==0)
				cnt++,k/=i;
			comp.pb(mp(i,cnt));
		}
	}
	if(k>1) comp.pb(mp(k,1));
	f(i,0,n){
		gett(x);
		f(j,0,comp.size()){
			int cnt=0,u=comp[j].F;
			while(x%u==0)
				cnt++,x/=u;
			if(comp[j].S<=cnt) mark[j]=1;
		}
	}
	f(i,0,comp.size()) if(!mark[i]) return cout<<"No",0;
	cout<<"Yes";
}