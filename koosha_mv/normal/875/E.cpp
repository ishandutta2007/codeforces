#include <bits/stdc++.h>
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

const int N=5e5+99;

int n,t,s1,s2,s[N];


bool check(int x){
	set<int> p;
	p.insert(s1);
	p.insert(s2);
	f(i,0,n){
		while(p.size() && *p.begin()<s[i]-x)
			p.erase(*p.begin());
		while(p.size() && s[i]+x<*p.rbegin())
			p.erase(*p.rbegin());
		if(p.size())
			p.insert(s[i]);
	}
	return (p.find(s[n-1])!=p.end());
}
void solve(){
	int l=abs(s1-s2)-1,r=1e9+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r;
}

int main(){
	cin>>n>>s1>>s2;
	f(i,0,n) gett(s[i]);
	solve();	
}