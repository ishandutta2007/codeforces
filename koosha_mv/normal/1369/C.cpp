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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,k,p,p1,a[N],w[N];

int main(){
	cin>>t;
	while(t--){
		ll ans=0;
		p=0;
		cin>>n>>k;
		f(i,0,n) gett(a[i]);
		f(i,0,k){ gett(w[i]); w[i]--; if(w[i]==0) p++; }
		sort(w,w+k);
		sort(a,a+n);
		f_(i,n-1,n-p) ans+=a[i]*2;
		f_(i,n-p-1,n-k) ans+=a[i];
		p1=n-k;
		f(i,p,k){
			p1-=w[i];
			ans+=a[p1];
		}
		cout<<ans<<endl;
	}
}