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
const int N=2e5+99;
ll a[N],m,n,t,p[N],b[N],c[N],g[N],ans;
int main(){
	get(t);
	f(q,0,t){
		ans=1;
		f(i,0,n+1) c[i]=g[i]=0;
		Get(n,m);
		f(i,0,n){get(a[i]);b[i]=a[i];}
		f(i,0,m){get(p[i]);c[p[i]]=1;}
		sort(b,b+n);
		sort(p,p+m);
		f_(i,n-1,0){
			if(c[i+1]==1)
				g[i]=g[i+1]+1;
		}
		int r=0;
		while(r<n){
			sort(a+r,a+r+g[r]+1);
			r=r+g[r]+1;
		}
		f(i,0,n){
			if(a[i]!=b[i]) ans=0;
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}