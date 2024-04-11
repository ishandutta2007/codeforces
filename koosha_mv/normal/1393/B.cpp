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

const int N=1e5+99;

int n,t,x,q,ans,mark[N];
set<pair<int,int> > s;

int main(){
	cin>>n;
	t=n;
	f(i,0,n){ gett(x); mark[x]++; }
	f(i,0,N)
		if(mark[i])	
			s.insert(mp(mark[i],i));
	cin>>q;
	f(i,0,q){
		char c;
		cin>>c;
		if(c=='+'){
			gett(x);
			s.erase(mp(mark[x],x));
			mark[x]++;
			s.insert(mp(mark[x],x));
		}
		else{
			gett(x);
			s.erase(mp(mark[x],x));
			mark[x]--;
			s.insert(mp(mark[x],x));
		}
		pair<int,int> u[3];
		f(i,0,3) u[i].F=u[i].S=0;
		f(i,0,3){
			if(s.size()){
				u[i]=*s.rbegin();
				s.erase(u[i]);
			}
		}
		f(i,0,3)
			if(u[i].F)
				s.insert(u[i]);
		if(u[0].F>=4 && u[1].F>=4 || (u[0].F>=4 && u[1].F>=2 && u[2].F>=2) || u[0].F>=8 || (u[0].F>=6 && u[1].F>=2))	cout<<"YES\n";
		else cout<<"NO\n";
	}
}