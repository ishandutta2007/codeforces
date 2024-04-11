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

const int N=1000;

int n,t,a[N],b[N];

int main(){
	cin>>t;
	f(q,0,t){
		int a1=0,a2=0,a3=1;
		cin>>n;
		f(i,0,n) cin>>a[i];
		f(i,0,n){cin>>b[i]; a1+=(b[i]==0); a2+=(b[i]==1);}
		f(i,1,n) if(a[i]<a[i-1]) a3=0;
		if(a3 || (a1 && a2)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}