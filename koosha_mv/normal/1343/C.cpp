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

int n,t,a[N];
ll ans;
bool c(int x,int y){
	if(x<y) swap(x,y);
	if(y<0 && x>0) return 1;
	return 0;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,0,n) gett(a[i]);
		ll mx=-1e9;ans=0;
		f(i,0,n+1){
			if(i!=0 &&(c(a[i],a[i-1]) || i==n))
				ans+=mx,mx=-1e9;
			maxm(mx,1ll*a[i]);
		}
		cout<<ans<<endl;
	}
}