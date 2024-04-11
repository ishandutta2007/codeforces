#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+9;
ll t,n,x,y,cx,a1,a2,mark[400],d=2;
int main(){
	cin>>x>>y;
	if(x==0 && y==0) return cout<<0,0;
	if(x>y) return cout<<-1,0;
	if(x==y) return cout<<1<<endl<<x,0;
	if((y-x)%2==0){
		cx=x;
		for(ll i=0;cx;i++){
			if(cx%2)
				mark[i]=1;
			cx/=2;
		}
		int k=0;
		a1=x,a2=0,t=y-x;
		for(ll i=0;t;i++){
			if(t%2){
				a1+=(1ll<<(i-1));
				a2+=(1ll<<(i-1));
				if(mark[i-1]==1)
					k=1;
			}
			t/=2;
		}
		if(k==0) return cout<<2<<endl<<a1<<" "<<a2,0;
		cout<<3<<endl;
		cout<<x<<" "<<(y-x)/d<<" "<<(y-x)/d;
		return 0;
	}
	cout<<-1;
}