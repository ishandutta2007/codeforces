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

const int n=3;

pair<ll,ll> a[n];

void ask(ll x){
	int u;
	cout<<x<<endl;
	cin>>u;
	if(u==0) exit(0);
	u--;
	f(i,0,n)
		if(a[i].S==u)
			a[i].F+=x;
	sort(a,a+n);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f(i,0,n){
		cin>>a[i].F;
		a[i].S=i;
	}
	cout<<"First"<<endl;
	ask(1e9);
	ask(a[2].F+a[2].F-a[1].F-a[0].F);
	ask(a[2].F-a[1].F);
}