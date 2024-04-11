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
const int N=3e5+9;
ll n,t,a[N],x,sum,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		f(i,0,n) cin>>a[i];
		sort(a,a+n);
		sum=0;
		ans=n;
		f_(i,n-1,0){
			sum+=a[i];
			if(sum/(n-i)<x){ans=n-i-1;break;}
		}
		cout<<ans<<endl;
	}
}