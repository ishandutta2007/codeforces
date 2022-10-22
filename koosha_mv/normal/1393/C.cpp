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

int n,x,q,a[N],t[N],mark[N];
set<pair<int,int> > s;

bool check(int x){
	s.clear();
	f(i,1,n+1) t[i]=mark[i];
	f(i,1,n+1)
		if(mark[i])
			s.insert(mp(mark[i],i));
	f(i,0,n){
		if(i>=x && t[a[i-x]])
			s.insert(mp(t[a[i-x]],a[i-x]));
		if(s.size()==0){ return 0; }
		pair<int,int> u=*s.rbegin();
		s.erase(u);
		a[i]=u.S;
		t[u.S]--;
	}
	return 1;
}
void Bs(){
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l-1<<'\n';
}

int main(){
	cin>>q;
	f(io,0,q){
		cin>>n;
		fill(mark,mark+n+2,0);
		f(i,0,n){
			gett(x);
			mark[x]++;
		}
		Bs();
	}
}