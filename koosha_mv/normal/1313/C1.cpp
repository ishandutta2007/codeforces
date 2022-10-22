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
const int N=2000;
ll n,t,m,a[N],ans,b[N],c[N],mx=-1;
int main(){
	cin>>n;
	f(i,0,n) get(a[i]);
	f(i,0,n){
		ans=a[i];
		c[i]=a[i];
		f_(j,i-1,0)
			c[j]=min(c[j+1],a[j]),ans+=c[j];
		f(j,i+1,n)
			c[j]=min(a[j],c[j-1]),ans+=c[j];
		if(ans>mx){
			mx=ans;
			f(j,0,n) b[j]=c[j];
		}
	}
	f(i,0,n) cout<<b[i]<<" ";
}