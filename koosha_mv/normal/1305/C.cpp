#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1010;
ll n,p,m[1010],b[N],mod,ans=1,a[300000];
int main(){
	cin>>n>>mod;
	f(i,0,n) cin>>a[i];
	if(n>mod){cout<<0;return 0;}
	f(i,0,n){
		f(j,0,i)
			ans=(ans*abs(a[i]-a[j]))%mod;
	}
	cout<<ans;
}