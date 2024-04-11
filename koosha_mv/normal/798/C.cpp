#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+99;
int n,t,g,a[N],ans,b[N];
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		g=__gcd(g,a[i]);
		if(a[i]%2==0 && i>0){
			ans+=b[i-1]/2;
			if(b[i-1]%2) ans+=2;
		}
		if(a[i]%2)
			b[i]=b[i-1]+1;
	}
	if(b[n-1]%2) ans+=2;
	ans+=b[n-1]/2;
	if(g>1) return cout<<"YES"<<endl<<0,0;
	cout<<"YES"<<endl<<ans;
}