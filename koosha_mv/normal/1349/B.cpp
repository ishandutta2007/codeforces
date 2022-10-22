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

int n,t,k,a[N],mx[N];

int main(){
	cin>>t;
	while(t--){
		int p1=0,gh=0,ans=0;
		cin>>n>>k;
		f(i,1,n+1) cin>>a[i]; 
		if(n==1 && a[1]==k) ans=2;
		f(i,1,n+1){
			p1--,p1+=(a[i]<k)*2;
			mx[i]=max(mx[i-1],p1);
		}
		p1=0;
		f(i,1,n+1){
			p1--,p1+=(a[i]>=k)*2;
			if(i>1 && p1+mx[i-2]>0) ans=1;	
		}
		f(i,1,n+1)
			if(a[i]==k && ans==1) ans=2;
		if(ans==2) cout<<"yes";
		else cout<<"no";
		cout<<endl;
	}
}