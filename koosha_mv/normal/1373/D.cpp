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
#define int ll

const int N=5e5+99;

int n,t,a[N];
ll p[N],ans,sum;

int mxsub(){
	ll mn=0,res=0;
	f(i,1,n+1)
		p[i]+=p[i-1];
	f(i,1,n+1){
		maxm(res,p[i]-mn);
		minm(mn,p[i]);
	}
	return res;
}
void case1(){
	f(i,1,n+1) p[i]=0;
	for(int i=0;i<n-1;i+=2)
		p[i/2+1]=a[i+1]-a[i];
	maxm(ans,mxsub());
}
void case2(){
	f(i,1,n+1) p[i]=0;
	for(int i=1;i<n-1;i+=2)
		p[i/2+1]=a[i]-a[i+1];
	maxm(ans,mxsub());
}

main(){
	cin>>t;
	while(t--){
		ans=0,sum=0;
		cin>>n;
		f(i,0,n){
			gett(a[i]);
			if(i%2==0)
				sum+=a[i];
		}
		case1();
		case2();
		cout<<ans+sum<<endl;
	}
}