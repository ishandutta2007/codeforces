#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+9;
ll n,t,a[N],ans,mn,mx,p;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		mx=-1;
		mn=1e9+2,ans=0;
		f(i,0,n) cin>>a[i];
		f(i,0,n){
			if(a[i]==-1){
				if(i>0 && a[i-1]!=-1){
					maxm(mx,a[i-1]);minm(mn,a[i-1]);
				}
				if(i<n-1 && a[i+1]!=-1){
					maxm(mx,a[i+1]);minm(mn,a[i+1]);
				}
			}
			if(i<n-1 && a[i]>=0 && a[i+1]>=0) maxm(ans,abs(a[i]-a[i+1]));
		}
		p=mx-mn;
		if(mn==1e9+2) p=0,mn=0,mx=0;
	//	cout<<p<<endl;
		maxm(ans,p/2+(p%2));
		cout<<ans<<" "<<(mn+mx)/2<<endl;
	}
}