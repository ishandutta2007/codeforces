#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9;
ll n,t,a[N],ans;

bool check(){
	f(i,0,n)
		f(j,0,i)
			if(a[i]==a[j] && a[i]!=0)
				return 1;
	return 0;
}
void solve(){
	f(i,0,n){
		f(j,0,i)
			if(a[i]==a[j] && a[i]!=0){
				a[i]--;
				return ;
			}
	}
}
int main(){
	cin>>n;
	f(i,0,n)
		cin>>a[i];
	while(check()){
		solve();
	}
	f(i,0,n) ans+=a[i];
	cout<<ans;
}