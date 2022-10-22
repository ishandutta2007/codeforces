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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+99;
int n,t,a[N],b[N],m1,m2,ans;
int main(){
	cin>>t;
	f(q,0,t){
		ans=1;
		cin>>n;
		m1=0,m2=0;
		f(i,0,n) cin>>a[i];
		f(i,0,n) cin>>b[i];
		f(i,0,n){
			if(a[i]>b[i] && m1==0) ans=0;
			if(a[i]<b[i] && m2==0) ans=0;
			if(a[i]==1) m2=1;
			if(a[i]==-1) m1=1;
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}