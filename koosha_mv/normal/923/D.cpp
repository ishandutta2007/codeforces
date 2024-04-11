#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,q,pars[N],part[N],Fs[N],Ft[N];
string s,t,ans;

bool solve(int a,int b,int c,int d){
	int u=min(Fs[b],b-a+1),v=min(Ft[d],d-c+1);
	if(u<v){
		return 0;
	}
	b-=v;
	d-=v;
	if(b<a){
		if(d<c) return 1;
		return 0;
	}
	int x=pars[b]-pars[a-1],y=part[d]-part[c-1];
	u=min(Fs[b],b-a+1);
	x+=2*(u%3 > 0);
	if(((x+y)&1) || x>y) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s>>t>>q;
	f(i,0,s.size()){
		pars[i+1]=pars[i]+(s[i]!='A');
		Fs[i+1]=Fs[i]+1;
		if(s[i]!='A') Fs[i+1]=0;
	}
	f(i,0,t.size()){
		part[i+1]=part[i]+(t[i]!='A');
		Ft[i+1]=Ft[i]+1;
		if(t[i]!='A') Ft[i+1]=0;
	}
	f(i,0,q){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		ans+=char('0'+solve(a,b,c,d));
	}
	cout<<ans;
}