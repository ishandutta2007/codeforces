#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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

const int N=5e5+99;

int n,t,a0[N],a1[N],b0[N],b1[N];
string s;

int main(){
	cin>>t;
	while(t--){
		cin>>s;
		s=' '+s;
		n=s.size();
		int ans=10005;
		f(i,1,n+1)
			a1[i]=a1[i-1]+(s[i]=='1'),a0[i]=a0[i-1]+(s[i]=='0');
		b1[n+1]=b0[n+1]=0;
		f_(i,n,1)
			b1[i]=b1[i+1]+(s[i]=='1'),b0[i]=b0[i+1]+(s[i]=='0');
		f(i,0,n)
			minm(ans,min(a0[i]+b1[i+1],a1[i]+b0[i+1]));
		cout<<ans<<endl;
	}
}